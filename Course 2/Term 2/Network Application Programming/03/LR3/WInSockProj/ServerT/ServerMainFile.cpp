#include <iostream>
#include <clocale>
#include <ctime>

#include "ErrorMsgText.h"
#include "Winsock2.h"

#pragma warning(disable : 4996)
#pragma comment(lib, "WS2_32.lib")  

int main()
{
    setlocale(LC_ALL, "rus");
    //---------------------------------------------  1 / 2
    WSADATA wsaData;

    SOCKET  sS;
    SOCKADDR_IN serv;

    serv.sin_family = AF_INET;
    serv.sin_port = htons(2000);
    serv.sin_addr.s_addr = INADDR_ANY;

    try {
        cout << "ServerU\n\n";

        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw  SetErrorMsgText("WSAStartup: ", WSAGetLastError());
        }

        // SOCK_DGRAM - сокет, ориентированный на сообщения
        if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET) {
            throw  SetErrorMsgText("socket: ", WSAGetLastError());
        }
        if (bind(sS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR) {
            throw  SetErrorMsgText("bind: ", WSAGetLastError());
        }
     //---------------------------------------------  3 / 4
        SOCKADDR_IN clientInfo;
        memset(&clientInfo, 0, sizeof(clientInfo));
        char ibuf[50];
        int lc = sizeof(clientInfo), lb = 0, lobuf = 0;
        clock_t start, end;
        bool flag = true;

        int counter = 0;

        while (true) {

            if ((lb = recvfrom(sS, ibuf, sizeof(ibuf), NULL, (sockaddr*)&clientInfo, &lc)) == SOCKET_ERROR) {
                throw  SetErrorMsgText("recvfrom: ", WSAGetLastError());
            }
            else {
                if (flag) {
                    flag = false;
                    start = clock();
                }
            }
            
            
            //if ((lobuf = sendto(sS, ibuf, strlen(ibuf) + 1, NULL, (sockaddr*)&clientInfo, lc)) == SOCKET_ERROR) {
            //    throw SetErrorMsgText("sendto: ", WSAGetLastError());
            //}
            
            counter++;
            if (counter == 1000) {
                Sleep(10000);
                counter = 0;
            }
            //слип если нужны ошибки
            if (strcmp(ibuf, "") == 0) {
                end = clock();
                flag = true;
                cout << "\nTime for sendto and recvfrom: " << ((double)(end - start) / CLK_TCK) << " c\n\n";
            }
            else {
                cout << ibuf << endl;
            }
           
        }
        //---------------------------------------------  5
        if (closesocket(sS) == SOCKET_ERROR) {
            throw  SetErrorMsgText("closesocket: ", WSAGetLastError());
        }
        if (WSACleanup() == SOCKET_ERROR) {
            throw  SetErrorMsgText("Cleanup: ", WSAGetLastError());
        }
    }
    catch (string errorMsgText) {
        cout << endl << errorMsgText;
    }

    system("pause");
    return 0;
}