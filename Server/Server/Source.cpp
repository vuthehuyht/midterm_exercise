#include"Server.h"
#include"Room.h"
int main() {
	Server server;
	for (int i = 0; i < 100; i++) {
		server.listenForNewConnection();
	}
	system("pause");
	return 0;
}