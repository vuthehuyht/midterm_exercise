#include "User.h"



User::User()
{
}

User::~User(){}

char* User::getUsername() {
	char* res = username;
	return res;
}

char* User::getNickname() {
	char* res = nickname;
	return res;
}
char* User::getRule() {
	char* res = rule;
	return res;
}
void User::setUsername(char _username[]) {
	strcpy_s(username, _username);
}

void User::setNickname(char _nickname[]) {
	strcpy_s(nickname, _nickname);
}

void User::setRule(char _rule[]) {
	strcpy_s(rule, _rule);
}
