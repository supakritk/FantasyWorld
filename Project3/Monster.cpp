#include "Monster.hpp"



Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::initStat(const int& id, const int & hp, const int & atk, const int & x, const int & y)
{
	this->setNumber(id);
	this->setHP(hp);
	this->setAtk(atk);
	this->setPosX(x);
	this->setPosY(y);
}

void Monster::randType(const int& size)
{
	m_type = rand() % size;
}

void Monster::setNumber(const int& id)
{
	m_id = id;
}

void Monster::setPosX(const int& x)
{
	m_posx = x;
}

void Monster::setPosY(const int& y)
{
	m_posy = y;
}

void Monster::setHP(const int& hp)
{
	m_HP = hp;
}

void Monster::setAtk(const int& atk)
{
	m_atk = atk;
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

int Monster::getAtk()
{
	return m_atk;
}

int Monster::getNumber()
{
	return m_id;
}

int Monster::getType()
{
	return TYPE;
}

void Monster::attacked(const int& dmg)
{
	m_HP -= dmg;
	if (m_HP < ABSOLUTE_ZERO)
		m_HP = ABSOLUTE_ZERO;
}



/*------------------------ Outdated ----------------------------- */
void Monster::spawn(const int& x, const int& y, const int& number)
{
	m_id = number;
	m_posx = x;
	m_posy = y;
	m_HP = rand() % START_HP + HP_RANGE;
}

void Monster::reduceHP()
{
	m_HP--;
}