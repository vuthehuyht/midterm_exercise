#pragma comment(lib,"ws2_32.lib")
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include<string>
#include "LoginForm1.h"
using namespace Client;
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
	Application::EnableVisualStyles();
	Client::LoginForm form;
	Application::Run(%form);
	return 0;
}