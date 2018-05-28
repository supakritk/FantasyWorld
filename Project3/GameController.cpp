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
		player = std::make_shared<Player>();
		metadata = std::make_shared<MetaData>();
		isStart = !isStart;
		return true;
	}
	else
	{
		std::cout << "Something goes wrong, game could not start." << std::endl;
 		return false;
	}
}

void GameController::gameEnd()
{
	if (isStart)
	{
		this->clearScreen();
		isStart = !isStart;
	}
	else
	{
		std::cout << "Game is not started yet." << std::endl;
	}
}

void GameController::clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

bool GameController::exit()
{
	return EXIT_SUCCESS;
}