#include <zmq.hpp>
#include <iostream>
#include <string.h>
#include <assert.h>
#include <thread>
#include <chrono>

#include "Lobby.h"

int main()
{
    static const int k_number_of_threads = 2;
    zmq::context_t context(k_number_of_threads);
    zmq::socket_t publisher(context, zmq::socket_type::pub);
    publisher.bind("tcp://*:5555");

    while (true)
    {
        std::string nya = "Nya";
        zmq::message_t zmq_msg(nya.begin(), nya.end());
        publisher.send(zmq_msg, zmq::send_flags::none);

        std::cout << "Sent: " << nya << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
