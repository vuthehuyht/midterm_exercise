#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<ctime>
#include "Config.h"

class Room
{
public:
	Room();
	~Room();
	static Room* getIntance();
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 5724396d1647f74dd77139ede4f6e1561a128b6f
	void removeLeftUser(std::string username);

	std::vector<std::string> getModData();
>>>>>>> discard1

	void createInforRoom(std::string username);
	std::string getOwner();
	std::string getTimeCreation();
	std::string getRuleChat();
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 5724396d1647f74dd77139ede4f6e1561a128b6f

	std::string getOwnerUsername() {
		return ownerUsername;
	}
	std::map<std::string, std::string> getFilterMap() {
		return filterData;
	}

	bool checkModUser(std::string username);
	bool checkBanUser(std::string username);
<<<<<<< HEAD
>>>>>>> discard1
=======
>>>>>>> 5724396d1647f74dd77139ede4f6e1561a128b6f
private:
	std::map<std::string, std::string> filterData;
	std::vector<std::string> banData;
	std::vector<std::string> modData;
	std::vector<std::string> memberData;

	std::string ownerUsername;
	std::string timeCreattion;
	std::string ruleChat;

	time_t t;

private:
	void saveBanList();
	void saveModList();
	void saveFilterList();
<<<<<<< HEAD
<<<<<<< HEAD
=======
	void saveMemberList();
>>>>>>> discard1
=======
	void saveMemberList();
>>>>>>> 5724396d1647f74dd77139ede4f6e1561a128b6f
	void createTime();

protected:
	static Room* _instance;
<<<<<<< HEAD
};
=======
};

>>>>>>> discard1
