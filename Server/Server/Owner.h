#pragma once
#include"Moderator.h"
class Owner : public Moderator
{
public:
	Owner();
	~Owner();

	void setInfor(std::string rules);
	void banUser(std::string username);
	void unbanUser(std::string username);
	void modUser(std::string username);
	void unModUser(std::string username);

private:

};
static Owner ownerptr;

