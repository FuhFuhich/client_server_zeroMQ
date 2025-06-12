#pragma once

#include <string>
#include <zmq.hpp>

#include "UserParser.h"
#include "UserStorage.h"

class Lobby
{
private:
	zmq::socket_t& subscriber;

public:
	Lobby(zmq::socket_t& subscriber);
	void get_messages(UserStorage& storage);
};
