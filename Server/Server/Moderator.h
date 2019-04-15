#pragma once
#include"User.h"
class Moderator : User
{
public:
	Moderator();
	~Moderator();

	void report();
};

