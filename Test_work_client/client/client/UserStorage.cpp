#include "UserStorage.h"

void UserStorage::add(const User& user)
{
	users.push_back(user);
}

void UserStorage::sort_by_fio()
{
	std::sort(users.begin(), users.end());
}

const std::vector<User>& UserStorage::get_users() const
{
	return users;
}
