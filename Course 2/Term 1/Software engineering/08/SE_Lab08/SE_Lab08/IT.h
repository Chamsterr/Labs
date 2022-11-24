#pragma once
#define ID_MAXSIZE 5 // ������������ ���-�� �������� � ��������������
#define TI_MAXSIZE 4096 // ���� ���-�� ����� � ������� ���������������
#define TI_INT_DEFAULT 0x00000000 // �������� �� ��������� ��� integer
#define TI_STR_DEFAULT 0x00 // �������� �� ��������� ��� string
#define TI_NULLIDX 0xffffffff // ��� �������� ������� ���������������
#define TI_STR_MAXSIZE 255 
#include <vector>

namespace IT
{
	enum IDDATATYPE {INT=1, STR=2}; // ���� ������ ���������������: integer, string
	enum IDTYPE { V=1, F=2, P=3, L=3}; // ���� ���������������: ����������, �������, ��������, �����

	struct Entry
	{
		int idxfirstLE; // ������ ������ ������ � ������� ������
		char id[ID_MAXSIZE]; // ��������������� (������������� ��������� �� ID_MAXSIZE)
		IDDATATYPE iddatatype; // ��� ������
		IDTYPE idtype; // ��� ���������������
		union
		{
			int vint; // �������� integer
			struct
			{
				char len; // ���-�� �������� � string
				char str[TI_STR_MAXSIZE - 1]; // ������� string
			} vstr[TI_STR_MAXSIZE];
		} value; // �������� ��������������

	};

	struct  IdTable // ���������� ������� ���������������
	{
		int maxsize; // ������� ������� ��������������� < TI_MAXSIZE
		int n; // ������� ������ ������� ��������������� < maxsize
		std::vector<Entry> table; //������ ����� ������� �������������

		IdTable(int ms);

		void Add(Entry entry);

		Entry GetEntry(int n);

		int IsId(char id[ID_MAXSIZE]);

		void Delete();
	};
}