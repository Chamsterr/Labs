#include "Header.h"

int main()
{
	Sleep(100);
	setlocale(LC_CTYPE, "Russian");

	GetLocalUnixTime();

	string IP = "127.0.0.1";

	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		throw GetLastError(WSAGetLastError());

	while (true) {
		int TC = 1000;
		int maxcorr = 0, mincorr = INT_MAX;
		__int64 mcorr = 0;
		__int64 mCcOs = 0;

		DWORD64 ClientTime = 0;
		SOCKET clientSocket;

		try
		{
			if ((clientSocket = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
				throw GetLastError(WSAGetLastError());

			SOCKADDR_IN serverParameters;
			serverParameters.sin_family = AF_INET;
			serverParameters.sin_port = htons(2000);
			serverParameters.sin_addr.s_addr = inet_addr(IP.c_str());

			GETSINCHRO gs;
			SETSINCHRO ss;
			ss.corrTime = 0;
			gs.mTime = 0;

			sendto(clientSocket, (char*)&gs, sizeof(gs), 0, (sockaddr*)&serverParameters, sizeof(serverParameters));
			int lc = sizeof(serverParameters);
			if ((recvfrom(clientSocket, (char*)&ss, sizeof(ss), NULL, (sockaddr*)&serverParameters, &lc)) == SOCKET_ERROR)
				throw GetLastError(WSAGetLastError());
			ClientTime = ss.corrTime;
			cout << "начальная коррекция: " << ss.corrTime << endl << endl;

			for (int i = 0; i < 10; i++)
			{
				Sleep(TC);
				//посылаем серверу запрос со своим временем
				ClientTime = gs.mTime = (DWORD64)ClientTime + TC;
				sendto(clientSocket, (char*)&gs, sizeof(gs), 0, (sockaddr*)&serverParameters, sizeof(serverParameters));

				//получаем с сервера корректировку
				int lc = sizeof(serverParameters);
				if ((recvfrom(clientSocket, (char*)&ss, sizeof(ss), NULL, (sockaddr*)&serverParameters, &lc)) == SOCKET_ERROR)
					throw GetLastError(WSAGetLastError());

				DWORD64 localUnixTime = GetLocalUnixTime();
				ClientTime = (ClientTime + ss.corrTime);
				mcorr = (mcorr + ss.corrTime);
				mCcOs = (mCcOs + (ClientTime - localUnixTime));
				maxcorr = (maxcorr < ss.corrTime) ? ss.corrTime : maxcorr;
				mincorr = (mincorr > ss.corrTime) ? ss.corrTime : mincorr;

				cout << "Время клиента: " << ClientTime << " Локальное время: " << localUnixTime << " Коррекция: " << ss.corrTime << endl;
				if (ClientTime > localUnixTime)
				{
					cout << "Время клиента больше на " << ClientTime - localUnixTime << endl;
				}
				else
				{
					cout << "Локальное время больше на " << localUnixTime - ClientTime << endl;
				}
				cout << endl;
			}
			cout << "avg correction: " << mcorr / 10.0 << endl;
			cout << "avg CC - OStime: " << mCcOs / 10.0 << endl;
			cout << "max correction: " << maxcorr << endl;
			cout << "min correction: " << mincorr << endl << endl;

			if (closesocket(clientSocket) == SOCKET_ERROR)
				throw GetLastError(WSAGetLastError());
		}
		catch (string errorMsgText)
		{
			cout << endl << errorMsgText << endl;
		}

		system("pause");
	}
	if (WSACleanup() == SOCKET_ERROR)
		throw GetLastError(WSAGetLastError());
	return 0;
}