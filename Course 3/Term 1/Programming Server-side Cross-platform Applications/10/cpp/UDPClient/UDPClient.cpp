#pragma warning(disable: 4996)

#include <iostream>
#include <string>

#pragma comment(lib, "WS2_32.lib") 
#include "Winsock2.h"

using namespace std;

void main()
{
	SOCKET s;
	WSADATA wsaData;

	try
	{
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
			throw "Startup failed";

		if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
			throw "Invalid socket";

		SOCKADDR_IN serv;
		serv.sin_family = AF_INET;
		serv.sin_port = htons(3000);
		serv.sin_addr.s_addr = inet_addr("127.0.0.1");

		char msg[300] = "Hello from client";

		if (sendto(s, msg, strlen(msg), 0, (SOCKADDR*)&serv, sizeof(serv)) == SOCKET_ERROR)
			throw "Send failed";

		cout << "Message sent" << endl;

		int bytes;
		int sserv = sizeof(serv);
		if ((bytes = recvfrom(s, msg, sizeof(msg), 0, (SOCKADDR*)&serv, &sserv)) == SOCKET_ERROR)
			throw "Receive failed";

		cout << "bytes " << bytes << endl;

		msg[bytes] = '\n';

		cout << "Message received: " << msg << endl;

		if (closesocket(s) == SOCKET_ERROR)
			throw "Close socket failed";

		if (WSACleanup() == SOCKET_ERROR)
			throw "Cleanup failed";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}