#include "Spawner.hpp"

Spawner::Spawner()
{
	metadata = std::make_shared<MetaData>();
}

Spawner::~Spawner()
{
}

void Spawner::spawn(const int& value, std::vector<std::vector<int>> mappos, std::vector<std::vector<int>> monspos)
{
	for (int i = ABSOLUTE_ZERO; i < value; i++)
	{
		mons_list.push_back(std::make_shared<Monster>());
		while (true)
		{
			this->setSpawnPoint(metadata->getRow(), metadata->getCol());
			if (mappos[posx][posy] == 0)
				break;
		}
		this->randType();
		mons_list[i]->initStat(i, randt, metadata->getMHp(randt), metadata->getMAtk(randt), posx, posy);
		mappos[posx][posy] = mons_list[i]->getType();
		monspos[posx][posy] = i;
	}
}

void Spawner::setSpawnPoint(const int & sizex, const int & sizey)
{
	posx = rand() % sizex;
	posy = rand() % sizey;
}

int Spawner::randType()
{
	randt = rand() % metadata->getSize();
	return randt;
}

std::shared_ptr<Monster> Spawner::getMonster(const int & id)
{
	return mons_list[id];
}
