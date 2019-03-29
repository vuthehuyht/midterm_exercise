#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>

using namespace std;

class Config
{
public:
	Config();
	~Config();
	void loadUserData();
	void saveUserData();
	void loadKey();
	map<string, string> getUserData();
private:
	std::fstream f;
	std::vector<string> keyData;
	map<string, string> userData;
	



};

