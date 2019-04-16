#pragma once
#include"User.h"
#include"Moderator.h"
#include"Room.h"
class Owner : public User
{
public:
	Owner();
	~Owner();

	void setInfor(std::string rules);
	void banUser(std::string username);
	void unbanUser(std::string username);
	void modUser(std::string username);
	void unModUser(std::string username);
};

