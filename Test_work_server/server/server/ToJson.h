#pragma once

#include <nlohmann/json.hpp>
#include <set>

#include "User.h"

class ToJson
{
public:
	static nlohmann::json create_users_json(const std::set<User>& users);
};
