#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include<iostream>
#include<ctime>
#include<vector>
#include<map>
#include<fstream>
#include "Owner.h"
class User
{
public:
	User();
	~User();

	enum online_status {
		OFFLINE,
		ONLINE,
	};

	enum member_status {
		BAN,
		UNBAN,
	};

	std::string getUsername();
	std::string getNickname();

	void setUsername(std::string _username);
	void setNickname(std::string _nickname);
	void leave();
	void info();
	void mods();
	void viewNickname();

protected:

	std::string username;
	std::string nickname;
	
	time_t t;
	std::string timeCreattion;
	std::string ruleChat;
protected:
	void getInforRoom();
	void createTime();
};

