#pragma once
#include "Monster.h"
class Map
{
public:
	Map();
	virtual ~Map();
	void initMap();
	void drawMap();
	int randPosX();
	int randPosY();
	void spawner();
	void nextTurn();
};

