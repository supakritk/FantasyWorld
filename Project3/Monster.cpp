#include "Monster.hpp"



Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::spawn(const int& x, const int& y)
{
	m_posx = x;
	m_posy = y;
	m_HP = rand() % START_HP + HP_RANGE;
}

void Monster::setHP()
{
	m_HP = rand() % START_HP + HP_RANGE;
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

int Monster::getRandAtk()
{
	m_atk = rand() % START_ATK + ATK_RANGE;
	return m_atk;
}