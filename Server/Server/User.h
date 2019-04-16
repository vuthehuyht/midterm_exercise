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
};

