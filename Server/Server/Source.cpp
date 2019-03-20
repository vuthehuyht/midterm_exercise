#include"Server.h"

int main() {
	Server server(1080);
	for (int i = 0; i < 100; i++) {
		server.listenForNewConnection();
	}
	system("pause");
	return 0;
}