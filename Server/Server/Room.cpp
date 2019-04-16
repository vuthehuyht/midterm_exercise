#include "Room.h"



Room::Room()
{
}


Room::~Room()
{
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
	configptr.getModList();
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
	for (std::vector<std::string>::iterator i = banData.begin(); i != banData.end(); i++) {
		if (username.compare(i->data()) == 0) {
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
	for (std::vector<std::string>::iterator i = modData.begin(); i != modData.end(); i++) {
		if (username.compare(i->data()) == 0) {
			modData.erase(i);
		}
	}
	saveModList();
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