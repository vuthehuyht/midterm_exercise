#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Config.h"
#include "Owner.h"
class Room
{
public:
	Room();
	~Room();
	
	void getFilterList();
	void getBanList();
	void getModList();
	void getMemberList();

	bool checkUsername(std::string username);
	void displayModOwner();
	void setRules(std::string rules);

private:

	Owner owner;
	std::map<std::string, std::string> filterData;
	std::vector<std::string> banData;
	std::vector<std::string> modData;
	std::vector<std::string> memberData;

	std::string timeCreattion;
	std::string ruleChat;
	
};
static Room roomptr;

