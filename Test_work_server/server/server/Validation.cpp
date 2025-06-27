#include "Validation.h"

bool Validation::validate_key(const int& key)
{
	return key >= 0;
}

bool Validation::validate_name(const std::string& name)
{
	std::regex name_pattern(R"([A-Za-zÀ-ßà-ÿ¨¸]+$)");

	return std::regex_match(name, name_pattern);
}

bool Validation::validate_date(const std::string& date)
{
	std::regex date_pattern(R"(^(0[1-9]|[12][0-9]|3[01])\.(0[1-9]|1[0-2])\.\d{4}$)");

	if (!std::regex_match(date, date_pattern))
	{
		return false;
	}

	int day = std::stoi(date.substr(0, 2));
	int month = std::stoi(date.substr(3, 2));
	int year = std::stoi(date.substr(6, 4));

	if (year < 1900 || year > 2025)
	{
		return false;
	}

	static const int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int max_day = days_in_month[month - 1];

	if (day < 1 || day > max_day)
	{
		return false;
	}

	return true;
}

bool Validation::validate_user(const User& user)
{
	bool valid = true;
	if (!validate_key(user.key)) valid = false;
	if (!validate_name(user.name)) valid = false;
	if (!validate_name(user.second_name)) valid = false;
	if (!validate_date(user.birthday)) valid = false;
	return valid;
}
