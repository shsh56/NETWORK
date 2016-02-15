#pragma once
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "5005"

class Network
{
private:
	struct addrinfo *result;
	struct addrinfo hints;

public:
	Network(void);
	~Network(void);
	SOCKET Connect(PCSTR ip, PCSTR port);
	SOCKET Bind(PCSTR ip, PCSTR port);
	SOCKET Listen(SOCKET ListenSocket);
	SOCKET Accept(SOCKET ListenSocket);
	void Send(SOCKET ConnectSocket, char sendbuf[DEFAULT_BUFLEN]);
	void Recv(SOCKET ConnectSocket, char recvbuf[DEFAULT_BUFLEN]);
};

