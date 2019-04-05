#define WIN32_LEAN_AND_MEAN
#pragma comment(lib, "Ws2_32.lib")
#include<thread>
#include "Config.h"
#include "Session.h"
#include<winsock.h>
class Server
{
public:
	Server(int port);
	bool listenForNewConnection();
	~Server();
	static void createHandle(SOCKET s, std::string username);

private:
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	SOCKET listening = INVALID_SOCKET;
	Config config;
};

