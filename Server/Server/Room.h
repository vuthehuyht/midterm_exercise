#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
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

	void addBanUser(std::string username);
	void removeBanUser(std::string username);
	void addModUser(std::string username);
	void removeModUser(std::string username);
	void addFilterWord(std::string keyword, std::string replace_keyword);
	void removeFilterWord(std::string keyword);
private:

//	Owner owner;
	std::map<std::string, std::string> filterData;
	std::vector<std::string> banData;
	std::vector<std::string> modData;
	std::vector<std::string> memberData;

	std::string timeCreattion;
	std::string ruleChat;

private:
	void saveBanList();
	void saveModList();
	void saveFilterList();
};
static Room roomptr;

