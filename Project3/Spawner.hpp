#pragma once
#include "Monster.hpp"
#include "MetaData.hpp"

class Spawner
{
private:
	int posx, posy, randt;
	std::vector < std::shared_ptr<Monster> > mons_list;

public:
	std::shared_ptr<MetaData> metadata;

	Spawner();
	~Spawner();
	void spawn(const int& value, std::vector<std::vector<int>> mappos, std::vector<std::vector<int>> monspos);
	void setSpawnPoint(const int& sizex, const int& sizey);
	int randType();
	std::shared_ptr<Monster> getMonster(const int& id);
};