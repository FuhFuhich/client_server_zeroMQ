#include <zmq.hpp>
#include <iostream>
#include <string.h>
#include <assert.h>

#include "User.h"
#include "UserParser.h"
#include "UserStorage.h"

int main()
{
    static const int k_number_of_threads = 2;
    zmq::context_t context(k_number_of_threads);
    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5555");

    UserStorage storage;
    subscriber.set(zmq::sockopt::subscribe, "");

    for (int i = 0; i < 6; ++i)
    {
        zmq::message_t zmq_msg;
        subscriber.recv(zmq_msg, zmq::recv_flags::none);

        std::string received_msg(static_cast<char*>(zmq_msg.data()), zmq_msg.size());

        User user;

        if (UserParser::parse(received_msg, user))
        {
            storage.add(user);
        }
    }

    storage.sort_by_fio();

    for (const auto& nya : storage.get_users())
    {
        std::cout << nya.key << " " << nya.name << " " << nya.second_name << " " << nya.birthday << "\n";
    }
}
