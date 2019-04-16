#pragma once
#include"User.h"
class Moderator : public User
{
public:
	Moderator();
	~Moderator();

	void report();
};

