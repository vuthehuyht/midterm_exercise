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
		for (vector<User>::iterator i = userData.begin(); i != userData.end(); i++) {
			f << i->getUsername() << endl;
			f << i->getNickname() << endl;
			f << i->getRule() << endl;
		}

	}

}
void Config::loadKey() {
	std::string data;
	f.open("keyData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		string line;
		while (!f.eof()) {
			getline(f, line);
			keyData.push_back(line);
		}
	}
	f.close();
}

bool Config::checkUsername(std::string username) {
	for (vector<User>::iterator i = userData.begin(); i != userData.end(); i++) {
		if (username.compare(string(i->getUsername())) == 0)
			return true;
	}
	return false;
}

vector<User> Config::getUserData() {
	return userData;
}
