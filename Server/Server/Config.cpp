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
		string usernameTemp;
		string ruleTemp;
		while (!f.eof()) {
			getline(f, data);
			if (i == 1) {
				usernameTemp = data;
				i++;
				continue;
			}
			if (i == 2) {
				ruleTemp = data;
				i++;
				if (i == 3) {
					pair<string, string> dataTemp = make_pair(usernameTemp, ruleTemp);
					userData.insert(dataTemp);
					i = 1;
				}
			}
			continue;
		}
	}
	f.close();
}
void Config::saveUserData() {
	f.open("testData.txt", std::ios::out);
	if (f.fail())
		std::cout << "Open file fail" << std::endl;
	else {
		for (std::map<string, string>::iterator a = userData.begin(); a != userData.end(); a++) {
			f << a->first << endl;
			f << a->second << endl;

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

map<string, string> Config::getUserData() {
	return userData;
}
