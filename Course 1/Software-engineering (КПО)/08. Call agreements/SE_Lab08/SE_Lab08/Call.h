#pragma once
#pragma once
namespace call {
	
	int _cdecl cdevl(int a, int b, int c)
	{return a + b + c;}
	int _stdcall cstd(int& a_ref, int b, int c)
	{ return a_ref * b * c; }
	int _fastcall cfst(int a, int b, int c, int d)
	{ return a + b + c + d; }
}































/*
��� ������ ���������� ���������� � ���������� �������, �� ���������� �����-
���� ���������� ������ ���, ������ 4 ����� �� ������, ����������� � ESP, ����� 
��������� ����� ��������, 4 ����� �� ������ (ESP + 4) ����� ��������� ������ 
��������, ��������� 4 ������ �� ������ (ESP + 8) ����� ��������� ������
��������

�������� EAX � ��� �������� ������ ����������
*/