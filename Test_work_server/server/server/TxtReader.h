#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <string>

#include "User.h"
#include "Validation.h"

class TxtReader
{
private:
	std::set<User> unique_users;
	User user;

public:
	TxtReader();
	void read_txt();
	std::set<User> get_unique_users();
};
