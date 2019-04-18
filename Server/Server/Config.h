#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
//using namespace std;

class Config
{
public:
	Config();
	~Config();

	void loadConfigServer();
	void loadFilterList();
	void loadBanList();
	void loadModList();
	void loadMemberList();

	std::vector<std::string> getMemberList();
	std::map<std::string, std::string> getFilterList();
	std::vector<std::string> getModList();
	std::vector<std::string> getBanList();
	std::string getIpServer();
	int getPortServer();
	
private:
	std::fstream f;

	std::map<std::string,std::string> filterData;
	std::vector<std::string >banData;
	std::vector<std::string> modData;
	std::vector<std::string> memberData;
	
	std::string ipServer;
	int portServer = 0;
};
static Config configptr;

