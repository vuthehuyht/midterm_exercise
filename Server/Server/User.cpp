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

void User::setUsername(char _username[]) {
	strcpy_s(username, _username);
}

void User::setNickname(char _nickname[]) {
	strcpy_s(nickname, _nickname);
}

void User::leave() {
	User::online_status::OFFLINE;
}

void User::viewNickname() {
	std::cout << nickname << std::endl;
}
