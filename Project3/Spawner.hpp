#pragma once
#include "Monster.hpp"

class Spawner
{
private:
	int posx, posy;

public:
	Spawner();
	~Spawner();
	bool spawn();
	bool setSpawnPoint(const int& x, const int& y);
	int getSpawnPointX();
	int getSpawnPointY();
};

