#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<string>
using namespace std;

class Config
{
public:
	Config();
	~Config();
	void loadUserData();
	void saveUserData();
	map<string, string> getUserData();
private:
	std::fstream f;
	map<string, string> userData;


};

