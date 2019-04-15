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