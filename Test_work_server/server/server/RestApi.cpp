#include "RestApi.h"

RestApi::RestApi(const TxtReader& txtReader) : txtReader(txtReader) { }

void RestApi::start()
{
	running = true;

	server_thread = std::thread([this]() {
		httplib::Server srv;

		srv.Get("/users", [this](const httplib::Request&, httplib::Response& res) {
			auto users = txtReader.get_unique_users();

			nlohmann::json j = ToJson::create_users_json(users);

			res.set_content(j.dump(4), "application/json");
			std::cout << "\n\n\n" << j.dump(4) << "\n\n\n";
		});

		srv.listen("0.0.0.0", 8080);
	});
}

void RestApi::stop()
{
	running = false;

	if (server_thread.joinable())
	{
		server_thread.join();
	}
}
