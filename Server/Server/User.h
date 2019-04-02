#pragma once
#include<string>
class User
{
public:
	User();
	~User();

	char* getUsername();
	char* getNickname();
	char* getRule();
	void setUsername(char _username[]);
	void setNickname(char _nickname[]);
	void setRule(char _rule[]);
private:
	char username[50];
	char nickname[50];
	char rule[3];
};

