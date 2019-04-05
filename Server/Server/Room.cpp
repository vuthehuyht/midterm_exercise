#include "Room.h"

Room::Room()
{
}


Room::~Room()
{
}

void Room::getUserList() {
	userDataList = config.getUserData();
}

bool Room::allowJoin(std::string username) {
	return true;
}
