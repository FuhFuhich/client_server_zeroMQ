#include "UserStorage.h"

void UserStorage::add(const User& user, const std::string& source)
{
	std::lock_guard<std::mutex> lock(mtx);
	source == "zmq" ? zmq_users.push_back(user) : http_users.push_back(user);
}

void UserStorage::sort_by_fio()
{
	std::lock_guard<std::mutex> lock(mtx);
	auto comparator = [](const User& a, const User& b) {return a < b; };
	std::sort(zmq_users.begin(), zmq_users.end(), comparator);
	std::sort(http_users.begin(), http_users.end(), comparator);
}

void UserStorage::print_users(const std::string& source) const
{
	std::lock_guard<std::mutex> lock(mtx);
	const auto& users = (source == "zmq") ? zmq_users : http_users;

	for (const auto& nya : users)
	{
		std::cout << nya.key << " " << nya.name << " " << nya.second_name << " " << nya.birthday << "\n";
	}
}
