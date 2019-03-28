#include"Server.h"
#include "Config.h"
int main() {
	Config config;
	config.loadUserData();
	config.saveUserData();
	map<string, string> userList;
	userList = config.getUserData();
	for (map<string, string>::iterator i = userList.begin(); i != userList.end(); i++) {
		cout << i->first << " " << i->second << endl;
	}
	system("pause");
	return 0;
}