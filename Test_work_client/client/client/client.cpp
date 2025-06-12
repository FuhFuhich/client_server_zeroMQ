#include <zmq.hpp>
#include <iostream>
#include <string.h>
#include <assert.h>

int main()
{
    static const int k_number_of_threads = 2;
    zmq::context_t context(k_number_of_threads);
    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5555"); // Заменить позже на айпишник сервера

    subscriber.set(zmq::sockopt::subscribe, "");

    while (true)
    {
        zmq::message_t zmq_msg;
        subscriber.recv(zmq_msg, zmq::recv_flags::none);

        std::string received_msg(static_cast<char*>(zmq_msg.data()), zmq_msg.size());
        std::cout << "From server: " << received_msg << "\n";
    }
}
