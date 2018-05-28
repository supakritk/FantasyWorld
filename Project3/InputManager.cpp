#include "InputManager.hpp"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

bool InputManager::readConfig(std::vector<std::string>& data)
{
	REQUIRE(data.empty());
	
	if (isRead)
	{
		std::cout << "File is already read." << std::endl;
		return false;
	}

	std::ifstream input(FILENAME);
	std::string line;
	std::string token;

	while (getline(input, line))
	{
		std::stringstream ss(line);
		while (getline(ss, token, ','))
		{
			data.push_back(token);
		}
	}

	isRead = !isRead;

	return true;
}
