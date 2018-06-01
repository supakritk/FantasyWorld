#pragma once
#include "Header.hpp"

class Monster
{
private:
	static const int START_HP = 3;
	static const int HP_RANGE = 5;
	static const int START_ATK = 1;
	static const int ATK_RANGE = 3;
	static const int TYPE = 1;

	int m_HP;
	int m_posx;
	int m_posy;
	int m_atk;
	int m_id;
	int m_type;

public:
	Monster();
	virtual ~Monster();
	void initStat(const int& id, const int& type_id, const int& hp, const int& atk, const int& x, const int& y);
	void setNumber(const int& id);
	void setMonsType(const int& type_id);
	void setPosX(const int& x);
	void setPosY(const int& y);
	void setHP(const int& type_id);
	void setAtk(const int& type_id);
	int getPosX();
	int getPosY();
	int getHP();
	int getAtk();
	int getType();
	int getNumber();
	void attacked(const int& dmg);


	/* Outdated */
	void spawn(const int& x, const int& y, const int& number);
	void reduceHP();
};

