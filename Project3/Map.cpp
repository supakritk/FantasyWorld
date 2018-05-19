#include "Map.hpp"


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

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mapdata[i][j] = INIT;
}

void Map::drawMap()
{
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < col; ++j)
		{
			//TO-DO: Draw map with color
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

void Map::setSpawnData(const int& x, const int& y, const int& type)
{
	mapdata[x][y] = type;
}

void Map::spawner()
{
	this->getTurn();
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
			monsters[value]->spawn(m_row, m_col);
			this->setSpawnData(m_row, m_col, monsters[value]->getType());
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
			this->setSpawnData(hero->getPosX(), hero->getPosY(), hero->getType());
		}
	}
}

void Map::getTurn()
{ 
	std::cout << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Turn: " << turn << std::endl;
	turn++;
}
















/*---------------------- Old Next Turn -----------------------------*/
void Map::nextTurn()
{
	for (int i = 0; i < m_number; i++)
	{
		monsters[i]->reduceHP();
		this->setSpawnData(monsters[i]->getPosX(), monsters[i]->getPosY(), monsters[i]->getHP());
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