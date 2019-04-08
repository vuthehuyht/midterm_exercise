#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#include<thread>
#include "Config.h"
#include "Session.h"
#include <winsock.h>
class Server
{
public:
	Server();
	bool listenForNewConnection();
	~Server();
	static void createHandle(SOCKET s);

private:
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	SOCKET listening = INVALID_SOCKET;
	Config config;
};

