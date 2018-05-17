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
	mapdata.resize(row, vector<int>(col));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mapdata[i][j] = INIT_HP;
}

void Map::drawMap()
{
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < col; ++j)
		{
			if (i == hero->getPosX() && j == hero->getPosY())
			{
				if(mapdata[i][j] < 10 && mapdata[i][j] != INIT_HP)
					cout << green << "-" << mapdata[i][j] << white << " ";
				else
					cout << green << mapdata[i][j] << white << " ";
			}
			else if (mapdata[i][j] < 10 && mapdata[i][j] != INIT_HP)
				cout << red << "-" << mapdata[i][j] << white << " ";
			else if(mapdata[i][j] == INIT_HP)
				cout << "--" << " ";
			else
				cout << mapdata[i][j] << " ";
		}
		cout << endl;
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

void Map::setSpawnData(const int& x, const int& y, const int& hp)
{
	mapdata[x][y] = hp;
}

void Map::setPlayerData(const int& x, const int& y, const int& hp)
{
	mapdata[x][y] = hp;
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

		if (mapdata[m_row][m_col] == INIT_HP)
		{
			monsters.push_back(make_shared<Monster>());
			monsters[value]->spawn(m_row, m_col);
			this->setSpawnData(m_row, m_col, monsters[value]->getHP());
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
		if (mapdata[p_row][p_col] == INIT_HP)
		{
			hero->summon(p_row, p_col);
			this->setPlayerData(hero->getPosX(), hero->getPosY(), hero->getHP());
		}
	}
}

void Map::getTurn()
{ 
	cout << endl;
	cout << "====================================================================================================" << endl;
	cout << endl;
	cout << "Turn: " << turn << endl;
	turn++;
}

void Map::nextTurn()
{
	for (int i = 0; i < m_number; i++)
	{
		monsters[i]->reduceHP();
		this->setSpawnData(monsters[i]->getPosX(), monsters[i]->getPosY(), monsters[i]->getHP());
		if (monsters[i]->getHP() == INIT_HP)
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