#include <zmq.hpp>
#include <iostream>
#include <string.h>
#include <assert.h>

int main()
{
    static const int k_number_of_threads = 2;
    zmq::context_t context(k_number_of_threads);
    zmq::socket_t socket(context, zmq::socket_type::rep);
    socket.bind("tcp://*:5555");

    while (true)
    {
        zmq::message_t request;

        auto result = socket.recv(request, zmq::recv_flags::none);
        std::cout << request.to_string() << "\n";

        std::string reply = "Nya";
        socket.send(zmq::buffer(reply), zmq::send_flags::none);
    }
}
