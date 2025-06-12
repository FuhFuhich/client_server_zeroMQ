#pragma once

#include <vector>
#include <algorithm>
#include <mutex>
#include <iostream>

#include "User.h"

class UserStorage
{
private:
	std::vector<User> zmq_users;
	std::vector<User> http_users;
	mutable std::mutex mtx;

public:
	void add(const User& user, const std::string& source);
	void sort_by_fio();
	void print_users(const std::string& source) const;
};
