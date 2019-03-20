#pragma comment(lib,"ws2_32.lib")
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include<string>

SOCKET connection;

void initSocket(std::string ip, int port) {
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		return;
	}

	sockaddr_in addr;
	int addrlen = sizeof(addr);
	inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	connection = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		MessageBoxA(NULL, "Failed to connect", "Error", MB_OK || MB_ICONERROR);
		return;
	}
}

int main() {
	std::cout << "1. Create room" << std::endl;
	std::cout << "2. Join room" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Enter your choise: ";
	int choise;
	std::cin >> choise;
	while (choise <= 0 || choise >= 4) {
		std::cout << "Enter your choise again: ";
		std::cin >> choise;
	}

	if (choise == 1) {
		std::string ip;
		int port;
		std::cout << "Enter server IP: ";
		std::getline(std::cin, ip);
		std::cout << "Enter server port: ";
		std::cin >> port;
		initSocket(ip, port);
	}

	if (choise == 2) {
		initSocket("127.0.0.1", 1080);
		char data[1024];
		ZeroMemory(data, sizeof(data));
		strcpy_s(data, "Hello server!");
		send(connection, data, sizeof(data), 0);
		ZeroMemory(data, sizeof(data));
		recv(connection, data, sizeof(data), 0);
		std::cout << data << std::endl;
	}
	
	if (choise == 3) {
		exit(0);
	}

	system("pause");
	return 0;
}