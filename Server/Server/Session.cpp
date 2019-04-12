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
	char completeMess[1024];

	while (true) {
		ZeroMemory(buffer, sizeof(buffer));
		ZeroMemory(completeMess, sizeof(completeMess));
		if (recv(s, buffer, sizeof(buffer), 0) > 0) {
			std::cout << getTimePrint() << " " << username << " " << buffer << std::endl;
			loggerptr.WriteMessagse(std::string(buffer), username, getTimeLog());
			strcat_s(completeMess, username.c_str());
			strcat_s(completeMess, ": ");
			strcat_s(completeMess, buffer);
			
			for (std::map<SOCKET, std::string>::iterator i = connections.begin(); i != connections.end(); i++) {
				if (i->first != s) {
					send(i->first, completeMess, sizeof(completeMess), 0);
				}
			}
		}
		else {
			std::cout << "Client disconnected!" << std::endl;
			removeConnection(s);
			std::cout << "Size of connections: " << connections.size() << std::endl;
			break;
		}
	}
}

void Session::removeConnection(SOCKET s) {
	connections.erase(s);
}

void Session::setTime() {
	t = time(0);
	struct tm* time_info = localtime(&t);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
	timeStr = std::string(buffer);
	char buffer_1[80];
	strftime(buffer_1, sizeof(buffer_1), "%H:%M", time_info);
	timeStr_1 = std::string(buffer_1);
}

std::string Session::getTimeLog() {
	setTime();
	return timeStr;
}

std::string Session::getTimePrint() {
	setTime();
	return timeStr_1;
}
