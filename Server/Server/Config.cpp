#include "Config.h"



Config::Config()
{
}


Config::~Config()
{
}
void Config::loadUserData() {
	std::string data;
	f.open("userData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		int i = 1;
		User user;
		while (!f.eof()) {
			getline(f, data);
			char dataTemp[100];
			strcpy_s(dataTemp, data.c_str());
			if (i == 1) {
				user.setUsername(dataTemp);	
				i++;
				continue;
			} 
			else if (i == 2) {
				user.setNickname(dataTemp);
				i++;
				continue;
			}
			else if (i == 3) {
				user.setRule(dataTemp);
				i++;
				if (i == 4) {
					userData.push_back(user);
					i = 1;
				}
			}
		}
	}
	f.close();
}
void Config::saveUserData() {
	f.open("testData.txt", std::ios::out);
	if (f.fail())
		std::cout << "Open file fail" << std::endl;
	else {
		for (std::vector<User>::iterator i = userData.begin(); i != userData.end(); i++) {
			f << i->getUsername() << std::endl;
			f << i->getNickname() << std::endl;
			f << i->getRule() << std::endl;
		}

	}

}
void Config::loadKey() {
	std::string data;
	f.open("keyData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		std::string line;
		while (!f.eof()) {
			std::getline(f, line);
			keyData.push_back(line);
		}
	}
	f.close();
}

void Config::loadConfigServer() {
	std::string data;
	f.open("configServer.txt", std::ios::in);

	if (f.fail())
		std::cerr << "Opening file fail" << std::endl;
	else {
		int index = 1;
		while (!f.eof()) {
			std::getline(f, data);
			if (index == 1) {
				ipServer = data;
				index++;
				continue;
			}
			if (index == 2) {
				std::stringstream ss(data);
				ss >> portServer;
				index = 1;
			}
		}
		f.close();
	}
}

bool Config::checkUsername(std::string username) {
	for (std::vector<User>::iterator i = userData.begin(); i != userData.end(); i++) {
		if (username.compare(std::string(i->getUsername())) == 0)
			return true;
	}
	return false;
}

std::vector<User> Config::getUserData() {
	return userData;
}

std::string Config::getIpServer() {
	return ipServer;
}

int Config::getPortServer() {
	return portServer;
}
