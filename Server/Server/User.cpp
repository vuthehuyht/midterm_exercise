#include "User.h"



User::User()
{

}


User::~User()
{
}

std::string User::getUsername() {
	return username;
}

std::string User::getNickname() {
	return nickname;
}

int User::getType() {
	if (t == ADMIN)
		return 0;
	if (t == MODERATOR)
		return 1;
	return 2;
}

int User::getOnlineStatus() {
	if (os == ONLINE)
		return 1;
	return 0;
}

int User::getMemberStatus() {
	if (ms == BAN)
		return 0;
	return 1;
}

void User::setUsername(std::string _username) {
	username = _username;
}

void User::setNickname(std::string _nickname) {
	nickname = _nickname;
}

void User::setAdmin() {
	t = ADMIN;
}

void User::setMod() {
	t = MODERATOR;
}

void User::setNormal() {
	t = NORMAL;
}

void User::setOnline() {
	os = ONLINE;
}

void User::setOffline() {
	os = OFFLINE;
}

void User::setBanMember() {
	ms = BAN;
}

void User::setUnbanMember() {
	ms = UNBAN;
}

