#pragma once

#include <thread>
#include <atomic>

#include "TxtReader.h"
#include "httplib.h"
#include "ToJson.h"
#include "User.h"

class RestApi
{
private:
	const TxtReader& txtReader;
	std::thread server_thread;
	std::atomic<bool> running{false};

public:
	RestApi(const TxtReader& txtReader);
	void start();
	void stop();
};
