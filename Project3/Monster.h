#pragma once
#include "Header.h"
class Monster
{
public:
	Monster();
	virtual ~Monster();
	void spawn();
	int getPosX();
	int getPosY();
	void initHP();
	int getHP();
	void reduceHP();
};

