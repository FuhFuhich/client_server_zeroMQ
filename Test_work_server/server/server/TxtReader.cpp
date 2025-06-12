#include "TxtReader.h"

TxtReader::TxtReader() { }

void TxtReader::read_txt()
{
	std::ifstream first_file("student_file_1.txt");
	std::ifstream second_file("student_file_2.txt");

	if (!first_file.is_open())
	{
		std::cerr << "Не удалось открыть файл student_file_1\n";
	}
	if (!second_file.is_open())
	{
		std::cerr << "Не удалось открыть файл student_file_1\n";
	}

	while (first_file >> user.key >> user.name >> user.second_name >> user.birthday)
	{
		if (Validation::validate_user(user))
		{
			unique_users.insert(user);
		}
	}

	while (second_file >> user.key >> user.name >> user.second_name >> user.birthday)
	{
		if (Validation::validate_user(user))
		{
			unique_users.insert(user);
		}
	}

	for (const auto& nya : unique_users)
	{
		std::cout << nya.key << " " << nya.name << " " << nya.second_name << " " << nya.birthday << "\n";
	}
}
