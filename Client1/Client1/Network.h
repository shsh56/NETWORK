#pragma once
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#include "targetver.h"
#include "string"
#include <stdio.h>
#include <tchar.h>
using namespace std;
#undef UNICODE
#include <stdlib.h>
#define DEFAULT_BUFLEN 512

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

