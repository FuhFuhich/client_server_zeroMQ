#include "UserParser.h"

bool UserParser::parse(const std::string& line, User& user)
{
	std::istringstream iss(line);
	iss >> user.key >> user.name >> user.second_name >> user.birthday;

	return Validation::validate_user(user) ? true : false;
}
