#include "Lobby.h"

Lobby::Lobby(zmq::socket_t& subscriber) : subscriber(subscriber) { }

void Lobby::get_messages(UserStorage& storage)
{
    zmq::message_t zmq_msg;
    subscriber.recv(zmq_msg, zmq::recv_flags::none);

    std::string received_msg(static_cast<char*>(zmq_msg.data()), zmq_msg.size());

    User user;

    if (UserParser::parse(received_msg, user))
    {
        storage.add(user, "zmq");
    }
}
