#pragma once

#include <vector>
#include <algorithm>

#include "User.h"

class UserStorage
{
private:
	std::vector<User> users;

public:
	void add(const User& user);
	void sort_by_fio();
	const std::vector<User>& get_users() const;
};
