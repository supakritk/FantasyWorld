#pragma once
#include "Header.hpp"
#include "MetaData.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "Map.hpp"
#include "InputManager.hpp"

class GameController
{
private:
	bool isStart = false;

public:
	std::shared_ptr<InputManager> input_manager;
	std::shared_ptr<Map> map;
	std::shared_ptr<Player> player;
	std::shared_ptr<MetaData> metadata;

	GameController();
	~GameController();
	bool gameStart();
	void gameEnd();
	bool exit();
	void clearScreen();
};

