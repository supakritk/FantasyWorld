#include "Map.hpp"

inline std::ostream& blue(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
		| FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& red(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& green(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& yellow(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& white(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return s;
}

Map::Map()
{
}

Map::Map(const int& x, const int& y, const int& number)
{
	this->setNumber(number);
	this->setRow(x);
	this->setCol(y);
}

Map::Map(const int& number)
{
	this->setNumber(number);
}

Map::~Map()
{
}

void Map::initMap()
{	
	mapdata.resize(row, std::vector<int>(col));
	monsterdata.resize(row, std::vector<int>(col));

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++)
		{
			mapdata[i][j] = INIT;
		}
	}
}

void Map::ClearScreen()
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

void Map::displayStat()
{
	int monstervalue = monsterdata[hero->getPosX()][hero->getPosY()];

	if (hero->getFlag())
	{
		std::cout << red << "Hero is death." << std::endl;
		std::cout << red << "GAME OVER" << white << std::endl;
	}
	else	
		std::cout << yellow << "Hero HP: " << hero->getHP() << white << std::endl;

	if (mapdata[hero->getPosX()][hero->getPosY()] == T_BOTH)
		std::cout << red << "Monster HP: " << monsters[monstervalue]->getHP() << white << std::endl;
}

void Map::drawMap()
{
	this->ClearScreen();
	this->getTurn();
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < col; ++j)
		{
			if (mapdata[i][j] == INIT)
				std::cout << EMPTY << EMPTY << " ";
			else if(mapdata[i][j] == T_MONSTER)
				std::cout << EMPTY << red << MONSTER << white << " ";
			else if (mapdata[i][j] == T_HERO)
				std::cout << green << HERO << white << EMPTY << white << " ";
			else if (mapdata[i][j] == T_BOTH)
				std::cout << green << HERO << red << MONSTER << white << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	this->displayStat();
}

void Map::setRow(const int& x)
{
	row = x;
}

void Map::setCol(const int& y)
{
	col = y;
}

int Map::getRow() 
{
	return row;
}

int Map::getCol()
{
	return col;
}

int Map::randPosX() 
{
	return rand()% row;
}

int Map::randPosY()
{
	return rand() % col;
}

void Map::setNumber(const int& number)
{
	m_number = number;
}

void Map::setMapData(const int& x, const int& y, const int& type)
{
	mapdata[x][y] = type;
}

void Map::setMonsterData(const int& x, const int& y, const int& value)
{
	monsterdata[x][y] = value;
}

void Map::spawner()
{
	for (int i = 0; i < m_number; i++)
	{
		this->singleSpawner(i);
	}
	this->playerSpawner();
	this->drawMap();
}

void Map::singleSpawner(const int& value)
{
	while (true)
	{
		int m_row = this->randPosX();
		int m_col = this->randPosY();

		if (mapdata[m_row][m_col] == INIT)
		{
			monsters.push_back(std::make_shared<Monster>());
			monsters[value]->spawn(m_row, m_col, value);
			this->setMonsterData(m_row, m_col, value);
			this->setMapData(m_row, m_col, monsters[value]->getType());
			break;
		}
	}
}

void Map::playerSpawner()
{
	while(hero->getFlag())
	{
		int p_row = this->randPosX();
		int p_col = this->randPosY();
		if (mapdata[p_row][p_col] == INIT)
		{
			hero->summon(p_row, p_col);
			this->setMapData(hero->getPosX(), hero->getPosY(), hero->getType());
		}
	}
}

void Map::getTurn()
{ 
	std::cout << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Turn: " << turn << std::endl;
	std::cout << std::endl;
	turn++;
}

void Map::checkPrev()
{
	if (mapdata[hero->getPosX()][hero->getPosY()] == T_BOTH)
		this->setMapData(hero->getPosX(), hero->getPosY(), T_MONSTER);
	else
		this->setMapData(hero->getPosX(), hero->getPosY(), INIT);
}

void Map::checkCurr()
{
	if (mapdata[hero->getPosX()][hero->getPosY()] == INIT)
		this->setMapData(hero->getPosX(), hero->getPosY(), hero->getType());
	else
		this->setMapData(hero->getPosX(), hero->getPosY(), T_BOTH);
}

void Map::playerMoveUp()
{
	if (hero->getPosX() != ABSOLUTE_ZERO)
	{
		this->checkPrev();
		hero->moveUp();
		this->checkCurr();
		this->drawMap();
	}
}
void Map::playerMoveLeft()
{
	if (hero->getPosY() != ABSOLUTE_ZERO) 
	{
		this->checkPrev();
		hero->moveLeft();
		this->checkCurr();
		this->drawMap();
	}
}
void Map::playerMoveDown()
{
	if (hero->getPosX() + 1 != row)
	{
		this->checkPrev();
		hero->moveDown();
		this->checkCurr();
		this->drawMap();
	}
}
void Map::playerMoveRight()
{
	if (hero->getPosY() + 1 != col)
	{
		this->checkPrev();
		hero->moveRight();
		this->checkCurr();
		this->drawMap();
	}
}

void Map::checkAfterAtk(const int& value)
{
	if (monsters[value]->getHP() == ABSOLUTE_ZERO && hero->getHP() > ABSOLUTE_ZERO)
	{
		this->setMapData(hero->getPosX(), hero->getPosY(), hero->getType());
		this->setMonsterData(hero->getPosX(), hero->getPosY(), NULL);
	}	
	else if (hero->getHP() == ABSOLUTE_ZERO && monsters[value]->getHP() > ABSOLUTE_ZERO)
		this->setMapData(hero->getPosX(), hero->getPosY(), T_MONSTER);
	else
		this->setMapData(hero->getPosX(), hero->getPosY(), INIT);
}

void Map::atkPhase()
{
	int monstervalue = monsterdata[hero->getPosX()][hero->getPosY()];
	int m_atk = monsters[monstervalue]->getRandAtk();
	int p_atk = hero->getRandAtk();

	hero->attacked(m_atk);
	monsters[monstervalue]->attacked(p_atk);

	this->checkAfterAtk(monstervalue);
	this->drawMap();
}

void Map::playerController()
{
	char _input;
	while (hero->getFlag() == false)
	{
		_input = _getch();
		if (_input == 'w' || _input == 'W') 
		{
			this->playerMoveUp();
		}
		else if (_input == 'a' || _input == 'A')
		{
			
			this->playerMoveLeft();
		}
		else if (_input == 's' || _input == 'S')
		{
			
			this->playerMoveDown();
		}
		else if (_input == 'd' || _input == 'D')
		{
			this->playerMoveRight();
		}
		else if (_input == 'q' || _input == 'Q')
		{
			if (mapdata[hero->getPosX()][hero->getPosY()] == T_BOTH)
				this->atkPhase();
			else
				std::cout << "No monster here.";
		}
	}
}

















/*---------------------- Old Next Turn -----------------------------*/
void Map::nextTurn()
{
	for (int i = 0; i < m_number; i++)
	{
		monsters[i]->reduceHP();
		this->setMapData(monsters[i]->getPosX(), monsters[i]->getPosY(), monsters[i]->getHP());
		if (monsters[i]->getHP() == ABSOLUTE_ZERO)
		{
			this->singleSpawner(i);
		}
	}
}

void Map::autoNextTurn()
{
	clock_t startt, endt;
	float difft;
	startt = clock();
	bool con = true;
	while (con)
	{
		endt = clock();
		difft = ((float)endt - (float)startt) / CLOCKS_PER_SEC;
		if (difft > DIFF)
		{
			startt = clock();
			this->getTurn();
			this->nextTurn();
			this->drawMap();
		}
		if (turn > MAX_TURN)
			con = !con;
	}
}

/*---------------------- END Old Next Turn -----------------------------*/