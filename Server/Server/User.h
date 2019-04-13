#pragma once
#include<string>
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

private:

	char username[50];
	char nickname[50];
};

