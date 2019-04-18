#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <winsock.h>
#include <map>
#include <string>
#include <ctime>
#include <sstream>
#include "Logger.h"
#include "ControlCenter.h"
#include "User.h"
#include "Room.h"
#include "Config.h"
class Session
{
public:
	Session();
	~Session();
	static Session* getIntance();
	void addConnection(SOCKET s, std::string username);
	void messageHandle(SOCKET s);
	void removeConnection(SOCKET s);

	std::string getTimeLog();
	std::string getTimePrint();
	void setRuleUser();
	void setOwner(std::string username);
	void setUserOnline(std::string username);

private:
	std::map<SOCKET, std::string> connections;
	std::map<std::string, User> userList;
	time_t t;
	std::string timeStr;
	std::string timeStr_1;

private:
	void setTime();
	std::vector<std::string> splitMessage(char message[]);
protected:
	static Session* _instance;
};
static Session sessionptr;
