#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Config.h"
class Room
{
public:
	Room();
	~Room();
	
	void getFilterList();
	void getBanList();
	void getModList();
	void getMemberList();

private:

	//Owner owner;
	std::map<std::string, std::string> filterData;
	std::vector<std::string> banData;
	std::vector<std::string> modData;
	std::vector<std::string> memberData;
	
	Config config;
};

