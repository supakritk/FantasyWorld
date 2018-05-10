#include "Map.h"



Map::Map()
{
}

Map::Map(int x, int y, int percent)
{
	this->setNumber(x, y, percent);
	this->setRow(x);
	this->setCol(y);
}

Map::Map(int percent)
{
	this->setNumber(percent);
}


Map::~Map()
{
	for (int i = 0; i < row; i++)
	{
		delete[] mapdata[i];
	}
	delete[] mapdata;
	delete[] monsters;
}

void Map::initMap()
{
	mapdata = new int*[row];

	for (int i = 0; i < row; i++)
		mapdata[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mapdata[i][j] = 0;
}

void Map::drawMap()
{
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < col; ++j)
		{
			if (mapdata[i][j] < 10 & mapdata[i][j] != 0)
				cout << "-" << mapdata[i][j] << " ";
			else if(mapdata[i][j] == 0)
				cout << "--" << " ";
			else
				cout << mapdata[i][j] << " ";
		}
		cout << endl;
	}
}

void Map::setRow(int x)
{
	row = x;
}

void Map::setCol(int y)
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

void Map::setNumber(int x, int y, int percent)
{
	m_number = (x * y) * (percent / 100.0);
}

void Map::setNumber(int percent)
{
	m_number = (row * col) * (percent / 100.0);
}

void Map::setSpawnData(int x, int y, int hp) 
{
	mapdata[x][y] = hp;
}

void Map::spawner()
{
	for (int i = 0; i < m_number; i++)
	{
		this->singleSpawner(i);
	}
}

void Map::singleSpawner(int value)
{
	while (true)
	{
		int m_row = this->randPosX();
		int m_col = this->randPosY();

		if (mapdata[m_row][m_col] == 0)
		{
			monsters[value].spawn(m_row, m_col);
			this->setSpawnData(m_row, m_col, monsters[value].getHP());
			break;
		}
	}
}

void Map::nextTurn()
{
	clock_t startt, endt;
	float difft;
	startt = clock();
	while (true)
	{
		endt = clock();
		difft = ((float)endt - (float)startt)/CLOCKS_PER_SEC;
		if (difft > 3.0)
		{
			startt = clock();
			cout << endl;
			cout << "====================================================================================================" << endl;
			cout << endl;
			for (int i = 0; i < m_number; i++)
			{
				monsters[i].reduceHP();
				this->setSpawnData(monsters[i].getPosX(), monsters[i].getPosY(), monsters[i].getHP());
				if (monsters[i].getHP() == 0)
				{
					this->singleSpawner(i);
				}
			}
			this->drawMap();
		}
	}
}