#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "ErrMsgs.h"
#include <iostream>
#include <clocale>
#include <ctime>

#include "Winsock2.h"                
#pragma comment(lib, "WS2_32.lib")   

bool  GetRequestFromClient(char* name, short port, struct sockaddr* from, int* flen);
bool PutAnswerToClient(char* name, sockaddr* to, int* lto);
void GetServer(char* call, short port, struct sockaddr* from, int* flen);
SOCKET  sS;

int main()
{
    setlocale(LC_ALL, "rus");

    WSADATA wsaData;
    SOCKADDR_IN serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(2000);
    serv.sin_addr.s_addr = INADDR_ANY;



    try {

        if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
        {
            throw  SetErrorMsgText("Startup:", WSAGetLastError());
        }

        std::cout << "ServerB\n\n";

        char name[] = "Hello";
        char err[] = "---Eror name---";
        SOCKADDR_IN client;
        int lc = sizeof(client);
        GetServer(name, 2000, (sockaddr*)&client, &lc);


            if (GetRequestFromClient(name, 2000, (sockaddr*)&client, &lc)) {
                std::cout << std::endl << PutAnswerToClient(name, (sockaddr*)&client, &lc);
            }
            else {
                std::cout << std::endl << PutAnswerToClient(err, (sockaddr*)&client, &lc);
            }

            //Внесите изменения в программу ServerB для того, чтобы она выводила на экран консоли параметры клиента, отправившего правильный позывной в адрес сервера.  
            SOCKADDR_IN* addr = (SOCKADDR_IN*)&client;
            std::cout << std::endl << "Port: " << addr->sin_port;
            std::cout << std::endl << "IP: " << inet_ntoa(addr->sin_addr);

            if (closesocket(sS) == SOCKET_ERROR)
            {
                throw  SetErrorMsgText("closesocket:", WSAGetLastError());
            }





        if (WSACleanup() == SOCKET_ERROR)
        {
            throw  SetErrorMsgText("Cleanup:", WSAGetLastError());
        }
    }
    catch (string errorMsgText) {
        cout << endl << errorMsgText;
    }

    main();
    return 0;
}

bool  GetRequestFromClient(

    char* name, //[in] позывной сервера  
    short            port, //[in] номер просушиваемого порта 
    struct sockaddr* from, //[out] указатель на SOCKADDR_IN
    int* flen  //[out] указатель на размер from 
) {

    SOCKADDR_IN serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    serv.sin_addr.s_addr = INADDR_ANY;

    int libuf = 0, lobuf = 0;
    char ibuf[50];

    if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET) {
        throw  SetErrorMsgText("socket: ", WSAGetLastError());
    }

    if (bind(sS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)
    {
        throw  SetErrorMsgText("bind:", WSAGetLastError());
    }


    if ((libuf = recvfrom(sS, ibuf, sizeof(ibuf), NULL, from, flen)) == SOCKET_ERROR) {
        if (WSAGetLastError() == WSAETIMEDOUT) return false;
        throw SetErrorMsgText("recv: ", WSAGetLastError());
    }

    if (strcmp(ibuf, name) == 0) {
        std::cout << "Name matches";
        return true;
    }
    else {
        std::cout << "Error name";
        return false;
    }

}

bool PutAnswerToClient(
    char* name, //[in] позывной сервера  
    struct sockaddr* to,   //[in] указатель на SOCKADDR_IN
    int* lto   //[in] указатель на размер from 
)
{
    if ((sendto(sS, name, strlen(name) + 1, NULL, to, *lto)) == SOCKET_ERROR)
    {
        throw  SetErrorMsgText("send:", WSAGetLastError());
    }

    return true;
}

void GetServer(char* call, short port, struct sockaddr* from, int* flen) {
    SOCKET cC;
    SOCKADDR_IN all;
    all.sin_family = AF_INET;
    all.sin_port = htons(port);
    all.sin_addr.s_addr = inet_addr("192.168.180.255");

    int timeout = 5000;

    int countServers = 1;
    int optval = 1;
    char buf[50];

    try {
        if ((cC = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET) {
            throw  SetErrorMsgText("socket:", WSAGetLastError());
        }
        if (setsockopt(cC, SOL_SOCKET, SO_BROADCAST, (char*)&optval, sizeof(int)) == SOCKET_ERROR) {
            throw  SetErrorMsgText("setsocketopt:", WSAGetLastError());
        }
        if (setsockopt(cC, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(int)) == SOCKET_ERROR) {
            throw  SetErrorMsgText("setsocketopt:", WSAGetLastError());
        }
        if (sendto(cC, call, strlen(call) + 1, NULL, (sockaddr*)&all, sizeof(all)) == SOCKET_ERROR) {
            throw SetErrorMsgText("sendto:", WSAGetLastError());
        }
        if (recvfrom(cC, buf, sizeof(buf), NULL, from, flen) == SOCKET_ERROR) {
            throw  SetErrorMsgText("recvfrom:", WSAGetLastError());
        }
        if (strcmp(call, buf) == 0) {
            countServers++;
            cout << "Server N" << countServers;
            cout << "\tIP: " << inet_ntoa(((SOCKADDR_IN*)from)->sin_addr) << endl;
            cout << "\t\tPort: " << ntohs(((struct sockaddr_in*)from)->sin_port) << endl;
        }
    }
    catch (string errorMsgText)
    {
        if (WSAGetLastError() == WSAETIMEDOUT) {
            cout << "Total number of servers with that callsign: " << countServers << endl;
            if (closesocket(cC) == SOCKET_ERROR) throw SetErrorMsgText("closesocket: ", WSAGetLastError());
        }
        else throw SetErrorMsgText("GetServer:", WSAGetLastError());
    }
}