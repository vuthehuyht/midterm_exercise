#include "Room.h"



Room::Room()
{
}


Room::~Room()
{
}
void Room::getFilterList() {
	filterData = config.getFilterList();
}
void Room::getBanList() {
	banData = config.getBanList();

}
void Room::getModList() {
	modData = config.getModList();

}
void Room::getMemberList() {
	memberData = config.getMemberList();

}