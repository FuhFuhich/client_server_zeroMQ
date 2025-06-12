#include "ToJson.h"

nlohmann::json ToJson::create_users_json(const std::set<User>& users)
{
	nlohmann::json j = nlohmann::json::array();

	for (const auto& nya : users)
	{
		j.push_back({
			{"key", nya.key},
			{"name", nya.name},
			{"second_name", nya.second_name},
			{"birthday", nya.birthday},
		});
	}

	return j;
}
