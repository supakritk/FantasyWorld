#include "Monster.h"



Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::spawn(int x, int y)
{
	m_posx = x;
	m_posy = y;
	m_HP = rand() % 10 + 5;
}

void Monster::setHP()
{
	m_HP = rand() % 10 + 5;
}

int Monster::getHP()
{
	return m_HP;
}

int Monster::getPosX()
{
	return m_posx;
}

int Monster::getPosY()
{
	return m_posy;
}

void Monster::reduceHP()
{
	m_HP--;
}