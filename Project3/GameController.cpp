#include "GameController.hpp"



GameController::GameController()
{
	this->gameStart();
}


GameController::~GameController()
{
}

bool GameController::gameStart()
{
	if (!isStart)
	{
		input_manager = std::make_shared<InputManager>();
		map = std::make_shared<Map>();
		spawner = std::make_shared<Spawner>();
		isStart = !isStart;
		return true;
	}
}

void GameController::gameEnd()
{
	if (isStart)
	{
		map->ClearScreen();
		isStart = !isStart;
	}
	else
	{
		std::cout << "Game is not started yet." << std::endl;
	}
}

bool GameController::exit()
{
	return EXIT_SUCCESS;
}

