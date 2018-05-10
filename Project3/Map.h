#pragma once
#include "Monster.h"
class Map
{
private:
	int m_number = 100;
	int row = 30;
	int col = 30;
	int **mapdata = nullptr;
	Monster *monsters = new Monster[m_number];
public:
	Map();
	Map(int x, int y, int percent);
	Map(int percent);
	virtual ~Map();
	void initMap();
	void setNumber(int x, int y, int percent);
	void setNumber(int percent);
	void setSpawnData(int x, int y, int hp);
	void drawMap();
	int randPosX();
	int randPosY();
	void setRow(int x);
	void setCol(int y);
	int getRow();
	int getCol();
	void spawner();
	void singleSpawner(int value);
	void nextTurn();
};

