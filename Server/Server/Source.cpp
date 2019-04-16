#include"Server.h"
#include "Owner.h"
int main() {
	Owner o;
	o.setNickname("huy");
	std::cout << o.getNickname() << std::endl;
	system("pause");
	return 0;
}