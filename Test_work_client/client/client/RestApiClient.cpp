#include <iostream>

#include "RestApiClient.h"
#include "Validation.h"

RestApiClient::RestApiClient(UserStorage& storage, const std::string& url) : storage(storage), server_url(url) {}

void RestApiClient::start()
{
    running = true;
    worker_thread = std::thread(&RestApiClient::run, this);
}

void RestApiClient::stop()
{
    running = false;

    if (worker_thread.joinable())
    {
        worker_thread.join();
    }
}

void RestApiClient::run()
{
    httplib::Client cli(server_url.c_str());

    while (running)
    {
        auto res = cli.Get("/users");
        if (res && res->status == 200)
        {
            try
            {
                auto j = nlohmann::json::parse(res->body);
                for (const auto& item : j)
                {
                    User user{
                        item["key"].get<int>(),
                        item["name"].get<std::string>(),
                        item["second_name"].get<std::string>(),
                        item["birthday"].get<std::string>()
                    };

                    if (Validation::validate_user(user))
                    {
                        storage.add(user, "restAPI");
                    }
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << "JSON error: " << e.what() << "\n";
            }
        }
        running = false;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
