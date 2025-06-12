#pragma once

#include <string>
#include <zmq.hpp>
#include <iostream>
#include <thread>
#include <chrono>

class Lobby
{
private:
	zmq::socket_t& publisher;

public:
	Lobby(zmq::socket_t& publisher);
	void send_message(const std::string& msg);
};
