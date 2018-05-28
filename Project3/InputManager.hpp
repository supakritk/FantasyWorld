#pragma once
#include "Header.hpp"

class InputManager
{
private:
	const std::string FILENAME = "config.txt";
	bool isRead = false;

public:

	InputManager();
	~InputManager();
	bool readConfig(std::vector<std::string>& data);
};

