#pragma once
#include"User.h"
class Moderator : public User
{
public:
	Moderator();
	~Moderator();

	void report();
	void filters();
	void filter(std::string keyword, std::string replace_keyword);
	void unFilter(std::string keyword);
	void privateMessage(std::string username);
};

