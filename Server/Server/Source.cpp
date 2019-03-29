#include"Server.h"
#include "Config.h"
int main() {
	Server server(1080);
	while (true) {
		server.listenForNewConnection();
	}
	system("pause");
	return 0;
}