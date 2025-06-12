#include "Lobby.h"
#include "TxtReader.h"

int main()
{
    static const int k_number_of_threads = 2;
    zmq::context_t context(k_number_of_threads);
    zmq::socket_t publisher(context, zmq::socket_type::pub);
    publisher.bind("tcp://*:5555");

    TxtReader txtReader;
    txtReader.read_txt();

    //Lobby lobby(publisher);
}
