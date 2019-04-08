#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include "User.h"
//using namespace std;

class Config
{
public:
	Config();
	~Config();

	void loadUserData();
	void saveUserData();
	void loadKey();
	void loadConfigServer();

	bool checkUsername(std::string username);

	std::vector<User> getUserData();
	
	std::string getIpServer();
	int getPortServer();
private:
	std::fstream f;
	std::vector<std::string> keyData;
	std::vector<User> userData;
	std::string ipServer;
	int portServer = 0;
};

