#include "Server.h"



Server::Server(int port){
	WSAData wsadata;
	WORD dllVersion = MAKEWORD(2, 1);

	if (WSAStartup(dllVersion, &wsadata) != 0) {
		MessageBox(NULL, "Winsock start faild", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // tao dia chi may chu
	addr.sin_port = htons(port); //tao cong ket noi
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
		std::cout << "Client connected!" << std::endl;
		char sucessMsg[255] = "Connect successfully!";
		send(newConnect, sucessMsg, sizeof(sucessMsg), 0);
		while (true) {
			ZeroMemory(data, sizeof(data));
			recv(newConnect, data, sizeof(data), 0);
			if (strcmp(data, "pp") == 0) {
				std::cout << "Client disconnected!" << std::endl;
				break;
			}
			std::cout << "Client: " << data << std::endl;
			strcat_s(data, "Server: ");
			send(newConnect, data, sizeof(data), 0);
		}
	}
	return true;
}


Server::~Server()
{
}
