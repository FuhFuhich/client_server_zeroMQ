#pragma once

#include <string>
#include <tuple>

struct User {
	int key;
	std::string name;
	std::string second_name;
	std::string birthday;

	bool operator<(const User& other) const
	{
		return std::tie(name, second_name, birthday) < std::tie(other.name, other.second_name, other.birthday);
	}
};
