#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "iostream"
#include "string.h"
#include "locale"
#include "time.h"
#include "Winsock2.h"
#pragma comment(lib, "WS2_32.lib")

using namespace std;

struct SETSINCRO
{
	string cmd;
	int correction;
};

struct GETSINCRO
{
	string cmd;
	int curvalue;
};

void PrintCurrentTime()
{
	SYSTEMTIME timeCheck;
	GetSystemTime(&timeCheck);

	std::cout << "�����: "
		<< timeCheck.wHour + 3 << ":"
		<< timeCheck.wMinute << ":"
		<< timeCheck.wSecond << "."
		<< timeCheck.wMilliseconds << " on "
		<< timeCheck.wDay << "/"
		<< timeCheck.wMonth << "/"
		<< timeCheck.wYear
		<< std::endl;
}

int calcAvgCorrection(int averageCorrection[], int length)
{
	int value = 0;
	int count = ++length;
	for (int i = 0; i < count; i++)
		value += averageCorrection[i];

	return value / count;
}

string GetLastError(int code)
{
	string msgText;



	switch (code)
	{
	case WSAEINTR:				 msgText = "������ ������� ��������\n";						  break;
	case WSAEACCES:				 msgText = "���������� ����������\n";						  break;
	case WSAEFAULT:				 msgText = "��������� �����\n";								  break;
	case WSAEINVAL:				 msgText = "������ � ���������\n";							  break;
	case WSAEMFILE:				 msgText = "������� ����� ������ �������\n";				  break;
	case WSAEWOULDBLOCK:		 msgText = "������ �������� ����������\n";					  break;
	case WSAEINPROGRESS:		 msgText = "�������� � �������� ��������\n";				  break;
	case WSAEALREADY: 			 msgText = "�������� ��� �����������\n";					  break;
	case WSAENOTSOCK:   		 msgText = "����� ����� �����������\n";						  break;
	case WSAEDESTADDRREQ:		 msgText = "��������� ����� ������������\n";				  break;
	case WSAEMSGSIZE:  			 msgText = "��������� ������� �������\n";				      break;
	case WSAEPROTOTYPE:			 msgText = "������������ ��� ��������� ��� ������\n";		  break;
	case WSAENOPROTOOPT:		 msgText = "������ � ����� ���������\n";					  break;
	case WSAEPROTONOSUPPORT:	 msgText = "�������� �� ��������������\n";					  break;
	case WSAESOCKTNOSUPPORT:	 msgText = "��� ������ �� ��������������\n";				  break;
	case WSAEOPNOTSUPP:			 msgText = "�������� �� ��������������\n";					  break;
	case WSAEPFNOSUPPORT:		 msgText = "��� ���������� �� ��������������\n";			  break;
	case WSAEAFNOSUPPORT:		 msgText = "��� ������� �� �������������� ����������\n";	  break;
	case WSAEADDRINUSE:			 msgText = "����� ��� ������������\n";						  break;
	case WSAEADDRNOTAVAIL:		 msgText = "����������� ����� �� ����� ���� �����������\n";	  break;
	case WSAENETDOWN:			 msgText = "���� ���������\n";								  break;
	case WSAENETUNREACH:		 msgText = "���� �� ���������\n";							  break;
	case WSAENETRESET:			 msgText = "���� ��������� ����������\n";					  break;
	case WSAECONNABORTED:		 msgText = "����������� ����� �����\n";						  break;
	case WSAECONNRESET:			 msgText = "����� �������������\n";							  break;
	case WSAENOBUFS:			 msgText = "�� ������� ������ ��� �������\n";				  break;
	case WSAEISCONN:			 msgText = "����� ��� ���������\n";							  break;
	case WSAENOTCONN:			 msgText = "����� �� ���������\n";							  break;
	case WSAESHUTDOWN:			 msgText = "������ ��������� send: ����� �������� ������\n";  break;
	case WSAETIMEDOUT:			 msgText = "���������� ���������� ��������  �������\n";		  break;
	case WSAECONNREFUSED:		 msgText = "���������� ���������\n";						  break;
	case WSAEHOSTDOWN:			 msgText = "���� � ����������������� ���������\n";			  break;
	case WSAEHOSTUNREACH:		 msgText = "��� �������� ��� �����\n";						  break;
	case WSAEPROCLIM:			 msgText = "������� ����� ���������\n";						  break;
	case WSASYSNOTREADY:		 msgText = "���� �� ��������\n";							  break;
	case WSAVERNOTSUPPORTED:	 msgText = "������ ������ ����������\n";					  break;
	case WSANOTINITIALISED:		 msgText = "�� ��������� ������������� WS2_32.DLL\n";		  break;
	case WSAEDISCON:			 msgText = "����������� ����������\n";						  break;
	case WSATYPE_NOT_FOUND:		 msgText = "����� �� ������\n";								  break;
	case WSAHOST_NOT_FOUND:		 msgText = "���� �� ������\n";								  break;
	case WSATRY_AGAIN:			 msgText = "������������������ ���� �� ������\n";			  break;
	case WSANO_RECOVERY:		 msgText = "�������������� ������\n";						  break;
	case WSANO_DATA:			 msgText = "��� ������ ������������ ����\n";				  break;
	case WSA_INVALID_HANDLE:	 msgText = "��������� ���������� �������  � �������\n";		  break;
	case WSA_INVALID_PARAMETER:	 msgText = "���� ��� ����� ���������� � �������\n";			  break;
	case WSA_IO_INCOMPLETE:		 msgText = "������ �����-������ �� � ���������� ���������\n"; break;
	case WSA_IO_PENDING:		 msgText = "�������� ���������� �����\n";					  break;
	case WSA_NOT_ENOUGH_MEMORY:	 msgText = "�� ���������� ������\n";						  break;
	case WSA_OPERATION_ABORTED:	 msgText = "�������� ����������\n";							  break;
	case WSAEINVALIDPROCTABLE:	 msgText = "��������� ������\n";							  break;
	case WSAEINVALIDPROVIDER:	 msgText = "������ � ������ �������\n";						  break;
	case WSAEPROVIDERFAILEDINIT: msgText = "���������� ���������������� ������\n";			  break;
	case WSASYSCALLFAILURE:		 msgText = "��������� ���������� ���������� ������\n";		  break;
	default:					 msgText = "Error\n";										  break;
	};

	return msgText;
}