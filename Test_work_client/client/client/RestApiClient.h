#pragma once

#include <thread>
#include <atomic>
#include <nlohmann/json.hpp>
#include <httplib.h>
#include <thread>

#include "UserStorage.h"

class RestApiClient
{
private:
	UserStorage& storage;
	std::string server_url;
	std::atomic<bool> running{ false };
	std::thread worker_thread;

private:
	void run();

public:
	RestApiClient(UserStorage& storage, const std::string& url);
	void start();
	void stop();
};
