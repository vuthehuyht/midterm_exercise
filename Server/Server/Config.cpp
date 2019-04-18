#include "Config.h"

Config::Config()
{
}


Config::~Config()
{
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

void Config::loadFilterList() {
	std::string data;
	f.open("filterData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		int index = 1;
		std::string key, value;
		while (!f.eof()) {
			std::getline(f, data);
			if (index == 1) {
				key = data;
				index++;
				continue;
			}
			if (index == 2) {
				value = data;
<<<<<<< HEAD
<<<<<<< HEAD
=======
				filterData.insert(std::make_pair(key, value));
>>>>>>> discard1
=======
				filterData.insert(std::make_pair(key, value));
>>>>>>> 5724396d1647f74dd77139ede4f6e1561a128b6f
				index = 1;
				continue;
			}
		}
		f.close();
	}
}
void Config::loadBanList(){
	f.open("banData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		std::string line;
		while (!f.eof()) {
			std::getline(f, line);
<<<<<<< HEAD
<<<<<<< HEAD
			banData.push_back(line);
=======
			if(line.empty() == false)
				banData.push_back(line);
>>>>>>> discard1
=======
			if(line.empty() == false)
				banData.push_back(line);
>>>>>>> 5724396d1647f74dd77139ede4f6e1561a128b6f
		}
	}
	f.close();
}
void Config::loadModList() {
<<<<<<< HEAD
	f.open("banData.txt", std::ios::in);
=======
	f.open("modData.txt", std::ios::in);
>>>>>>> discard1

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		std::string line;
		while (!f.eof()) {
			std::getline(f, line);
<<<<<<< HEAD
<<<<<<< HEAD
			modData.push_back(line);
=======
			if(line.empty() == false)
				modData.push_back(line);
>>>>>>> discard1
=======
			if(line.empty() == false)
				modData.push_back(line);
>>>>>>> 5724396d1647f74dd77139ede4f6e1561a128b6f
		}
	}
	f.close();
}
void Config::loadMemberList() {
	f.open("userData.txt", std::ios::in);

	if (f.fail())
		std::cout << "Opening file fail" << std::endl;
	else {
		std::string line;
		while (!f.eof()) {
			std::getline(f, line);
			memberData.push_back(line);
		}
	}
	f.close();
}
std::vector<std::string> Config::getMemberList() {
	return memberData;
}

std::vector<std::string> Config::getBanList() {
	return banData;
}

std::vector<std::string> Config::getModList() {
	return modData;
}

std::map<std::string, std::string> Config::getFilterList() {
	return filterData;
}

std::string Config::getIpServer() {
	return ipServer;
}

int Config::getPortServer() {
	return portServer;
}
