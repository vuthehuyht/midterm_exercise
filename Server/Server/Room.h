#pragma once
#include<vector>
#include "User.h"
#include "Config.h"
class Room
{
public:
	Room();
	~Room();

	void getUserList();
	bool allowJoin(std::string username);
private:
	std::vector<User> userDataList;
private:
	Config config;
};

