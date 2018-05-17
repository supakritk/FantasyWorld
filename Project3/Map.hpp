#pragma once
#include "Monster.hpp"
#include "Player.hpp"
class Map
{
private:
	const int INIT_HP = 0;
	const float DIFF = 2.0;
	const int MAX_TURN = 5;

	int m_number = 100;
	int row = 30;
	int col = 30;
	int turn = 1;
	
	vector<vector<int>> mapdata;
	vector<shared_ptr<Monster>> monsters;
	shared_ptr<Player> hero = make_shared<Player>();

public:
	Map();
	Map(const int& x, const int& y, const int& number);
	Map(const int& number);
	~Map();
	void initMap();
	void setNumber(const int& number);
	void setSpawnData(const int& x, const int& y, const int& hp);
	void setPlayerData(const int& x, const int& y, const int& hp);
	void drawMap();
	int randPosX();
	int randPosY();
	void setRow(const int& x);
	void setCol(const int& y);
	void getTurn();
	int getRow();
	int getCol();
	void spawner();
	void singleSpawner(const int& value);
	void playerSpawner();
	void autoNextTurn();
	void nextTurn();
};

