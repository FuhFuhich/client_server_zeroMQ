#include <zmq.hpp>
#include <iostream>
#include <string.h>
#include <assert.h>

int main()
{
    static const int k_number_of_threads = 2;
    zmq::context_t context(k_number_of_threads);
    zmq::socket_t socket(context, zmq::socket_type::req);
    socket.connect("tcp://localhost:5555"); // Заменить позже на айпишник сервера

    for (int i = 0; i < 10; ++i)
    {
        std::string msg = "Nya from client";
        socket.send(zmq::buffer(msg), zmq::send_flags::none);

        zmq::message_t reply;
        socket.recv(reply, zmq::recv_flags::none);

        std::cout << "From server: " << reply.to_string() << "\n";
    }
}
