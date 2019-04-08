#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include<winsock.h>
#include<map>
#include<string>
#include"Logger.h"
class Session
{
public:
	Session();
	~Session();
	void addConnection(SOCKET s, std::string username);
	void messageHandle(SOCKET s);

private:
	std::map<SOCKET, std::string> connections;
	Logger logger;
};

