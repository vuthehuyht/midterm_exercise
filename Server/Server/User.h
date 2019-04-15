#pragma once
#include<string>
#include <iostream>
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

	char* getUsername();
	char* getNickname();

	void setUsername(char _username[]);
	void setNickname(char _nickname[]);
	void leave();
	void info();
	void mods();
	void viewNickname();

protected:

	char username[50];
	char nickname[50];
};

