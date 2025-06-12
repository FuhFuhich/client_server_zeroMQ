#include "Lobby.h"

Lobby::Lobby(zmq::socket_t& publisher) : publisher(publisher) {}

void Lobby::send_message(std::string msg)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    zmq::message_t zmq_msg(msg.begin(), msg.end());
    publisher.send(zmq_msg, zmq::send_flags::none);

    std::cout << "Sent: " << msg << "\n";
}
