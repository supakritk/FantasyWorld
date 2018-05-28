#include "MetaData.hpp"



MetaData::MetaData()
{
}


MetaData::~MetaData()
{
}

void MetaData::arrangeData()
{
	for (int i = 0 ; i < raw_data.size() ; i++)
	{
		if (i % SEPERATOR == 0)
		{
			m_name_data.push_back(raw_data[i]);
		}
		else if (i % SEPERATOR == 1)
		{
			m_hp_data.push_back(std::stoi(raw_data[i]));
		}
		else if (i % SEPERATOR == 2)
		{
			m_atk_data.push_back(std::stoi(raw_data[i]));
		}
	}
}

int MetaData::getSize()
{
	return m_name_data.size();
}

std::string MetaData::getMName(const int& id)
{
	return m_name_data[id];
}

int MetaData::getMHp(const int& id)
{
	return m_hp_data[id];
}

int MetaData::getMAtk(const int & id)
{
	return m_atk_data[id];
}