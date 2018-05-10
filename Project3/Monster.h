#pragma once
#include "Header.h"
class Monster
{
private:
	int m_HP;
	int m_posx;
	int m_posy;
public:
	Monster();
	virtual ~Monster();
	int getPosX();
	int getPosY();
	void spawn(int x, int y);
	void setHP();
	int getHP();
	void reduceHP();
};

