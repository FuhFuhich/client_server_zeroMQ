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

	std::string cast_to_string() const
	{
		return std::to_string(key) + " " + name + " " + second_name + " " + birthday;
	}
};
