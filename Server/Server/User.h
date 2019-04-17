#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include<iostream>
#include<ctime>
#include<vector>
#include<map>
#include<fstream>
#include "Room.h"

enum online_status {
	OFFLINE,
	ONLINE,
};

enum member_status {
	BAN,
	UNBAN,
};

enum Type {
	ADMIN,
	MODERATOR,
	NORMAL,
};
class User
{
public:
	User();
	~User();

	std::string getUsername();
	std::string getNickname();

	void setUsername(std::string _username);
	void setNickname(std::string _nickname);
	void leave();
	void info();
	void mods();
	void viewNickname();
	void setAdmin();
private:
	std::string username;
	std::string nickname;
	Type t;
	online_status os;
	member_status ms;
	Room* rptr;
};

