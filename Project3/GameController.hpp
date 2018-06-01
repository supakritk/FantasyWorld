#pragma once
#include "Header.hpp"
#include "Spawner.hpp"
#include "Map.hpp"
#include "InputManager.hpp"

class GameController
{
private:
	bool isStart = false;

public:
	std::shared_ptr<InputManager> input_manager;
	std::shared_ptr<Map> map;
	std::shared_ptr<Spawner> spawner;

	GameController();
	~GameController();
	bool gameStart();
	void gameEnd();
	bool exit();
};

