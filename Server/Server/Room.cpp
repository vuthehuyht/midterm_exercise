#include "Room.h"

Room *Room::_instance = 0;

Room::Room()
{
}


Room::~Room()
{
}

Room* Room::getIntance() {
	if (_instance == NULL) {
		_instance = new Room();
	}
	return _instance;
}

void Room::getFilterList() {
	configptr.loadFilterList();
	filterData = configptr.getFilterList();
}

void Room::getBanList() {
	configptr.loadBanList();
	banData = configptr.getBanList();
}

void Room::getModList() {
	configptr.loadModList();
	modData = configptr.getModList();
}

void Room::getMemberList() {
	configptr.loadMemberList();
	memberData = configptr.getMemberList();
}

bool Room::checkUsername(std::string username) {
	for (std::vector<std::string>::iterator i = memberData.begin(); i != memberData.end(); i++) {
		if (username.compare(i->data()) == 0)
			return true;
	}
	return false;
}

void Room::displayModOwner() {
	
}

void Room::setRules(std::string rules) {
	ruleChat = rules;
}

void Room::addBanUser(std::string username) {
	banData.push_back(username);
	saveBanList();
}

void Room::removeBanUser(std::string username) {
	if (banData.size() == 1) {
		banData.erase(banData.begin());
	}
	else {
		for (std::vector<std::string>::iterator i = banData.begin(); i != banData.end(); i++) {
			if (i->compare(username) == 0)
				banData.erase(i);
		}
	}
	saveBanList();
}

void Room::addModUser(std::string username) {
	modData.push_back(username);
	saveModList();
}

void Room::removeModUser(std::string username) {
	if (modData.size() == 1)
		modData.erase(modData.begin());
	else {
		for (std::vector<std::string>::iterator i = modData.begin(); i != modData.end(); i++) {
			if (i->compare(username) == 0) {
				modData.erase(i);
			}
		}
	}
	saveModList();
}


void Room::addFilterWord(std::string keyword, std::string replace_keyword) {
	filterData.insert(std::make_pair(keyword, replace_keyword));
	saveFilterList();
}

void Room::removeFilterWord(std::string keyword) {
	filterData.erase(keyword);
	saveFilterList();
}

void Room::saveBanList() {
	std::fstream f;
	f.open("banData.txt", std::ios::out);

	if (f.fail())
		std::cerr << "Opening file fail" << std::endl;
	else {
		for (std::vector<std::string>::iterator i = banData.begin(); i != banData.end(); i++) {
			f << i->data() << std::endl;
		}
	}
	f.close();
}

void Room::saveModList() {
	std::fstream f;
	f.open("modData.txt", std::ios::out);

	if (f.fail())
		std::cerr << "Opening file failed!" << std::endl;
	else {
		for (std::vector<std::string>::iterator i = modData.begin(); i != modData.end(); i++) {
			f << i->data() << std::endl;
		}
	}
	f.close();
}

void Room::saveFilterList() {
	std::fstream f;
	f.open("filterData.txt", std::ios::out);

	if (f.fail())
		std::cerr << "Opening fail failed!" << std::endl;
	else {
		for (std::map<std::string, std::string>::iterator i = filterData.begin(); i != filterData.end(); i++) {
			f << i->first << std::endl;
			f << i->second << std::endl;
 		}
	}
	f.close();
}

void Room::createTime() {
	t = time(0);
	struct tm* time_info = localtime(&t);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
	timeCreattion = std::string(buffer);
}

void Room::createInforRoom(std::string username) {
	ownerUsername = username;
	createTime();
}

std::string Room::getOwner() {
	std::string res;
	res = "Owner: " + ownerUsername;
	return res;
}

std::string Room::getTimeCreation() {
	std::string res;
	res = "Time created: " + timeCreattion;
	return res;
}

std::string Room::getRuleChat() {
	std::string res;
	res ="Rules: "+ ruleChat;
	return res;
}

std::vector<std::string> Room::getModData() {
	return modData;
}
bool Room::checkModUser(std::string username) {
	for (std::vector<std::string>::iterator i = modData.begin(); i != modData.end(); i++) {
		if (username.compare(i->data()) == 0)
			return true;
	}
	return false;
}

void Room::removeLeftUser(std::string username) {
	if (memberData.size() == 1)
		memberData.erase(memberData.begin());
	else {
		for (std::vector<std::string>::iterator i = memberData.begin(); i != memberData.end(); i++) {
			if (i->compare(username) == 0)
				memberData.erase(i);
		}
	}
	saveMemberList();
}

void Room::saveMemberList() {
	std::fstream f;
	f.open("userData.txt", std::ios::out);

	if (f.fail())
		std::cerr << "Opening file failed!" << std::endl;
	else {
		for (std::vector<std::string>::iterator i = memberData.begin(); i != memberData.end(); i++) {
			f << i->data() << std::endl;
		}
	}
	f.close();
}

bool Room::checkBanUser(std::string username) {
	for (std::vector<std::string>::iterator i = banData.begin(); i != banData.end(); i++) {
		if (i->compare(username) == 0)
			return true;
	}
	return false;
}