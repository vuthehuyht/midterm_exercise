#include "Owner.h"



Owner::Owner()
{
}


Owner::~Owner()
{
}

void Owner::setInfor(std::string rules) {
	roomptr.setRules(rules);
}

void Owner::banUser(std::string username) {
	roomptr.addBanUser(username);
}
