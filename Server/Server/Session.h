#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include<winsock.h>
#include<map>
#include<string>
#include<ctime>
#include<sstream>
#include"Logger.h"
class Session
{
public:
	Session();
	~Session();
	void addConnection(SOCKET s, std::string username);
	void messageHandle(SOCKET s);
	void removeConnection(SOCKET s);
	std::string getTimeLog();
	std::string getTimePrint();

private:
	std::map<SOCKET, std::string> connections;
	time_t t;
	std::string timeStr;
	std::string timeStr_1;

private:
	void setTime();
};
static Session sessionptr;
