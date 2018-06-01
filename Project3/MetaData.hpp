#pragma once
#include "Header.hpp"

class MetaData
{
private:
	static const int SEPERATOR = 3;
	
	int row, col;
		 
public:

	std::vector<std::string> raw_data;
	std::vector<std::string> m_name_data;
	std::vector<int> m_hp_data;
	std::vector<int> m_atk_data;

	MetaData();
	~MetaData();
	void arrangeData();
	int getSize();
	std::string getMName(const int& id);
	int getMHp(const int& id);
	int getMAtk(const int& id);
	int getRow();
	int getCol();
};

