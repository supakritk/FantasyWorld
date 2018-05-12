#pragma once
#include "Header.hpp"
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
	void spawn(const int& x, const int& y);
	void setHP();
	int getHP();
	void reduceHP();
};

