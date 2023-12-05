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
		serv.sin_addr.s_addr = INADDR_ANY;

		if (bind(s, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)
			throw "Bind failed";

		cout << "Server is started" << endl;

		SOCKADDR_IN clnt;
		int lclnt = sizeof(clnt);

		while (true)
		{
			char msg[100];
			int lmsg = recvfrom(s, msg, sizeof(msg), 0, (sockaddr*)&clnt, &lclnt);
			msg[lmsg] = '\0';

			cout << "Message received: " << msg << endl;

			string smsg = "ECHO: "s + string(msg);

			if (sendto(s, smsg.c_str(), smsg.size() + 1, 0, (sockaddr*)&clnt, sizeof(clnt)) == SOCKET_ERROR)
				throw "Send failed";
		}

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