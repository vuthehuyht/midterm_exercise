#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "User.h"
using namespace std;

class Config
{
public:
	Config();
	~Config();

	void loadUserData();
	void saveUserData();
	void loadKey();
	bool checkUsername(std::string username);
	vector<User> getUserData();
private:
	std::fstream f;
	std::vector<string> keyData;
	vector<User> userData;
};

