#include "Lobby.h"
#include "TxtReader.h"
#include "RestApi.h"

int main()
{
    static const int k_number_of_threads = 5;
    zmq::context_t context(k_number_of_threads);
    zmq::socket_t publisher(context, zmq::socket_type::pub);
    publisher.bind("tcp://*:5555");

    TxtReader txt_reader;
    txt_reader.read_txt();

    Lobby lobby(publisher);

    std::thread zmq_thread([&]() {
        for (const auto& nya : txt_reader.get_unique_users())
        {
            lobby.send_message(nya.cast_to_string());
        }
    });

    // RestAPI
    RestApi rest_api(txt_reader);
    rest_api.start();

    zmq_thread.join();
    rest_api.stop();
}
