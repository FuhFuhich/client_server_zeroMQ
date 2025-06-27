#include <zmq.hpp>
#include <iostream>
#include <string.h>
#include <assert.h>

#include "User.h"
#include "UserParser.h"
#include "UserStorage.h"
#include "Lobby.h"
#include "RestApiClient.h"

int main()
{
    static const int k_number_of_threads = 5;
    zmq::context_t context(k_number_of_threads);
    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5555");

    UserStorage storage;
    subscriber.set(zmq::sockopt::subscribe, "");
    Lobby lobby(subscriber);

    std::thread zmq_thread([&]() {
        while (true)
        {
            lobby.get_messages(storage);
        }
    });

    RestApiClient rest_api_client(storage, "http://localhost:8080");

    rest_api_client.start();

    while (true)
    {
        storage.sort_by_fio();

        std::cout << "\nFrom zmq:\n";
        storage.print_users("zmq");

        std::cout << "\nFrom restAPI:\n";
        storage.print_users("restAPI");

        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    zmq_thread.join();
    rest_api_client.stop();
}
