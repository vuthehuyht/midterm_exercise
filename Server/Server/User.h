#pragma once
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
	int getType();
	int getOnlineStatus();
	int getMemberStatus();
<<<<<<< HEAD
=======

	void setUsername(std::string _username);
	void setNickname(std::string _nickname);
	void setAdmin();
	void setMod();
	void setNormal();
	void setOnline();
	void setOffline();
	void setBanMember();
	void setUnbanMember();
private:
	std::string username;
	std::string nickname;
	Type t;
	online_status os;
	member_status ms;
};
>>>>>>> discard1

	void setUsername(std::string _username);
	void setNickname(std::string _nickname);
	void setAdmin();
	void setMod();
	void setNormal();
	void setOnline();
	void setOffline();
	void setBanMember();
	void setUnbanMember();
private:
	std::string username;
	std::string nickname;
	Type t;
	online_status os;
	member_status ms;
};