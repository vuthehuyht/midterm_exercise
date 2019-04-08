#include "Server.h"



Server::Server(){
	WSAData wsadata;
	WORD dllVersion = MAKEWORD(2, 1);

	if (WSAStartup(dllVersion, &wsadata) != 0) {
		MessageBox(NULL, "Winsock start failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}
	config.loadConfigServer();
	addr.sin_addr.s_addr = inet_addr(config.getIpServer().c_str());  // tao dia chi may chu
	addr.sin_port = htons(config.getPortServer()); //tao cong ket noi
	addr.sin_family = AF_INET; //dat loai dia chi ip la ipv4

	// tao socket de lang nghe ket noi den
	listening = socket(AF_INET, SOCK_STREAM, NULL);
	//ket noi dia chi toi socket 
	if (bind(listening, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		std::string errorMsg = "Faild to bind the address to listening socket! Winsock error: " + std::to_string(WSAGetLastError());
		MessageBoxA(NULL, errorMsg.c_str(), "Error", MB_OK || MB_ICONERROR);
		exit(1);
	}
	if (listen(listening, SOMAXCONN) == SOCKET_ERROR) {
		std::string errorMsg = "Fail listening on listen socket! Winsock error: " + std::to_string(WSAGetLastError());
		MessageBoxA(NULL, errorMsg.c_str(), "Error", MB_OK || MB_ICONERROR);
		exit(1);
	}
	std::cout << config.getIpServer() << ":" << config.getPortServer() << std::endl;
	config.loadUserData();
	config.loadKey();
}
bool Server::listenForNewConnection() {
	std::cout << "Waiting..." << std::endl;
	SOCKET newConnect = accept(listening, (SOCKADDR*)&addr, &addrlen);
	if (newConnect == 0) {
		std::cout << "Fail to accept the client connection. " << std::endl;
		return false;
	}
	else {
		char data[1024];
		ZeroMemory(data, sizeof(data));
		recv(newConnect, data, sizeof(data), 0);
		if (config.checkUsername(std::string(data))) {
			sessionptr.addConnection(newConnect, std::string(data));
			std::cout << "Client connected!" << std::endl;
			char sucessMsg[15] = "sucessfully";
			send(newConnect, sucessMsg, sizeof(sucessMsg), 0);
			std::thread t(createHandle, newConnect);
			t.detach();
		}
		else {
			char errMsg[100] = "Check username again!";
			send(newConnect, errMsg, sizeof(errMsg), 0);
		}
	}
	return true;
}


Server::~Server()
{
}

void Server::createHandle(SOCKET s) {
	sessionptr.messageHandle(s);
}
