#include"Server.h"
<<<<<<< HEAD
#include "Config.h"
#include "Room.h"
=======
#include"Room.h"
>>>>>>> discard1
int main() {
	Server server;
	for (int i = 0; i < 100; i++) {
		server.listenForNewConnection();
	}
	system("pause");
	return 0;
}