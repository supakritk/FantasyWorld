#pragma once
#include "Header.hpp"
class Monster
{
private:
	const int START_HP = 3;
	const int HP_RANGE = 5;
	const int START_ATK = 1;
	const int ATK_RANGE = 3;

	int m_HP;
	int m_posx;
	int m_posy;
	int m_atk;
public:
	Monster();
	virtual ~Monster();
	int getPosX();
	int getPosY();
	void spawn(const int& x, const int& y);
	void setHP();
	int getHP();
	void reduceHP();
	int getRandAtk();
};

