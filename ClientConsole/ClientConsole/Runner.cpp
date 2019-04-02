#pragma comment(lib,"ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h> 
#include <string> 
#include <iostream> 
#include <WS2tcpip.h>
#include <string>
#include <vector>

SOCKET connection;
void initSocket(std::string ip, int port) {
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		return;
	}

	sockaddr_in addr; //Address to be binded to our Connection socket
	int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
	inet_pton(AF_INET, ip.c_str(), &addr.sin_addr); //Address = localhost (this pc)
	addr.sin_port = htons(port); //Port = 1111
	addr.sin_family = AF_INET; //IPv4 Socket

	connection = socket(AF_INET, SOCK_STREAM, 0); //Set Connection socket
	if (connect(connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) //If we are unable to connect...
	{
		MessageBoxA(NULL, "Failed to connect", "Error", MB_OK | MB_ICONERROR);
		return; //Failed to Connect
	}
}
int main() {
	std::cout << "1. Create room" << std::endl;
	std::cout << "2. Join room" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Enter your choise: ";
	int userChoise;
	std::cin >> userChoise;
	while (userChoise < 0 || userChoise > 3) {
		std::cerr << "Lua chon khong hop le!" << std::endl;
		std::cin >> userChoise;
	}
	if (userChoise == 1) {
		initSocket("127.0.0.1", 1080);
	}
	if (userChoise == 2) {
		std::string ip;
		int port;
		std::cin.ignore();
		std::cout << "Enter server IP: ";
		getline(std::cin, ip);
		std::cout << "Enter port: ";
		std::cin >> port;

		system("cls");
		char data[1024];
		ZeroMemory(data, sizeof(data));
		std::cin.ignore();
		std::cout << "Enter your username: ";
		std::cin.get(data, 1024);

		initSocket(ip, port);

		send(connection, data, sizeof(data), 0);
		ZeroMemory(data, sizeof(data));
		recv(connection, data, sizeof(data), 0);
		std::cout << data << std::endl;

	} if (userChoise == 3) {
		exit(0);
	}
	system("pause");
	return 0;
}