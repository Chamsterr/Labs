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

		if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
			throw "Invalid socket";

		SOCKADDR_IN serv;
		serv.sin_family = AF_INET;
		serv.sin_port = htons(3000);
		serv.sin_addr.s_addr = INADDR_ANY;

		if (bind(s, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)
			throw "Bind failed";

		if (listen(s, 10) == SOCKET_ERROR)
			throw "Listen failed";

		cout << "Server is started" << endl;

		SOCKET c;
		SOCKADDR_IN clnt;
		int lclnt = sizeof(clnt);

		while (true)
		{
			if ((c = accept(s, (sockaddr*)&clnt, &lclnt)) == INVALID_SOCKET)
				throw "Accept failed";

			cout << "Client connected" << endl;

			char msg[100];
			int lmsg = recv(c, msg, sizeof(msg), 0);
			msg[lmsg] = '\0';

			cout << "Message received: " << msg << endl;

			string echo = "ECHO: ";
			echo += msg;

			send(c, echo.c_str(), echo.length(), 0);

			cout << "Message sent: " << echo << endl;

			closesocket(c);
			cout << "Client disconnected" << endl;
		}
	}
	catch (char* msg)
	{
		cout << msg << endl;
	}
}