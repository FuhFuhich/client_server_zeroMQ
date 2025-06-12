#pragma once

#include <string>
#include <regex>

#include "User.h"

class Validation
{
public:
	static bool validate_user(const User& user);

private:
	static bool validate_key(const int& key);
	static bool validate_name(const std::string& name);
	static bool validate_date(const std::string& date);
};
