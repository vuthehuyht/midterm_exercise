#include "Session.h"

Session::Session()
{
}


Session::~Session()
{
}

void Session::addConnection(SOCKET s, std::string username) {
	connections.insert(std::make_pair(s, username));
}

void Session::messageHandle(SOCKET s) {
	char buffer[1024];
	std::string username = connections[s];
	while (true) {
		ZeroMemory(buffer, sizeof(buffer));
		recv(s, buffer, sizeof(buffer), 0);
		for (std::map<SOCKET, std::string>::iterator i = connections.begin(); i != connections.end(); i++) {
			if (i->first != s) {
				logger.WriteMessagse(std::string(buffer), username);
				strcat_s(buffer, username.c_str());
				send(i->first, buffer, sizeof(buffer), 0);
			}
		}
	}
}
