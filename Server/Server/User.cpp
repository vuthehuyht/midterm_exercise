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
	roomptr.getInforRoom();
}

void User::setAdmin() {
	t = ADMIN;
}

