#include "Session.h"

Session::Session()
{
}


Session::~Session()
{
}

Session * Session::_instance = 0;

Session* Session::getIntance() {
	if (_instance == NULL) {
		_instance = new Session();
	}
	return _instance;
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
			std::vector<std::string> splitedMessage = splitMessage(buffer);
			std::vector<std::string>::iterator first = splitedMessage.begin();

			if (strcmp(first->data(), "/info") == 0) {
				strcpy_s(completeMess, Room::getIntance()->getOwner().c_str());
				strcat_s(completeMess, "\n");
				strcat_s(completeMess, Room::getIntance()->getTimeCreation().c_str());
				strcat_s(completeMess, "\n");
				strcat_s(completeMess, Room::getIntance()->getRuleChat().c_str());
				send(s, completeMess, sizeof(completeMess), 0);
				ZeroMemory(completeMess, sizeof(completeMess));
			}
			else if (strcmp(first->data(), "/nickname") == 0) {
				User temp = userList[username];
				strcpy_s(completeMess, temp.getNickname().c_str());
				send(s, completeMess, sizeof(completeMess), 0);
				ZeroMemory(completeMess, sizeof(completeMess));
			}
			else if (strcmp(first->data(), "/setnick") == 0) {
				User temp = userList[username];
				std::vector<std::string>::iterator second = splitedMessage.begin() + 1;
				temp.setNickname(second->data());
			}
			else if (strcmp(first->data(), "/mods") == 0) {
				strcat_s(completeMess, Room::getIntance()->getOwner().c_str());
				strcat_s(completeMess, "\n");
				strcat_s(completeMess, "Mods: ");
				std::vector<std::string> temp = Room::getIntance()->getModData();
				for (std::vector<std::string>::iterator i = temp.begin(); i != temp.end(); i++) {
					strcat_s(completeMess, i->c_str());
					strcat_s(completeMess, ",");
				}
				send(s, completeMess, sizeof(completeMess), 0);
				ZeroMemory(completeMess, sizeof(completeMess));
			}
			else {
				strcat_s(completeMess, username.c_str());
				strcat_s(completeMess, ": ");
				strcat_s(completeMess, buffer);
				controlptr.addMessage(std::string(completeMess));
				for (std::map<SOCKET, std::string>::iterator i = connections.begin(); i != connections.end(); i++) {
					if (i->first != s) {
						char temp[1024];
						ZeroMemory(temp, sizeof(temp));
						strcpy(temp, controlptr.getMessage().c_str());
						send(i->first, temp, sizeof(temp), 0);
					}
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

void Session::setRuleUser() {
	configptr.loadMemberList();
	std::vector<std::string> result = configptr.getMemberList();
	for (std::vector<std::string>::iterator i = result.begin(); i != result.end(); i++) {
		User userTmp;
		userTmp.setUsername(i->data());
		userTmp.setNickname(i->data());
		userTmp.setNormal();
		userList.insert(std::make_pair(i->data(), userTmp));
	}
}

void Session::setOwner(std::string username) {
	User user = userList[username];
	user.setAdmin();
}

std::vector<std::string> Session::splitMessage(char message[]) {
	char* p;
	char* next_token = NULL;
	std::vector<std::string> result;

	p = strtok_s(message, "., ", &next_token);
	while (p != NULL) {
		result.push_back(std::string(p));
		p = strtok_s(NULL, "., ", &next_token);
	}
	return result;
}
