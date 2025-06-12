#pragma once

#include <string>
#include <sstream>

#include "User.h"
#include "Validation.h"

class UserParser
{
public:
	static bool parse(const std::string& line, User& user);
};
