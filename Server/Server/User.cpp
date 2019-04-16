#include "User.h"



User::User()
{
}

User::~User(){}

std::string User::getUsername() {
	return username;
}

std::string User::getNickname() {
	return nickname;
}

void User::setUsername(std::string _username) {
	username = _username;
}

void User::setNickname(std::string _nickname) {
	nickname = _nickname;
}

void User::leave() {
	User::online_status::OFFLINE;
}

void User::viewNickname() {
	std::cout << nickname << std::endl;
}

void User::info() {
	
}

void User::createTime() {
	t = time(0);
	struct tm* time_info = localtime(&t);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
	timeCreattion = std::string(buffer);
}
