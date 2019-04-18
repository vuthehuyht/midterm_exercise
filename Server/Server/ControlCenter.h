#pragma once
#include<queue>
class ControlCenter
{
public:
	ControlCenter();
	~ControlCenter();

	void addMessage(std::string message);
	std::string getMessage();

private:
	std::queue<std::string> messages;
};

static ControlCenter controlptr;

