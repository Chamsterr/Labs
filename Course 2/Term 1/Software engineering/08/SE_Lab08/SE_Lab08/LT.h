#pragma once
#define LEXEMA_FIXSIZE 1 // ������������� ������ �������
#define LT_MAXSIZE 4096 // ������������ ���-�� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff // ��� �������� ������� ���������������
#define LEX_INTEGER 't' // ������� ��� integer
#define LEX_STRING 't' // ������� ��� string
#define LEX_ID 'i' // ������� ��� ��������������
#define LEX_LITERAL 'l' // ������� ��� ��������
#define LEX_FUNCTION 'f' // ������� ��� function
#define LEX_DECLARE 'd' // ������� ��� declare
#define LEX_RETURN 'r' // ������� ��� return
#define LEX_PRINT 'p' // ������� ��� print
#define LEX_SEMICOLON ';' // ������� ��� ;
#define LEX_COMMA ',' // ������� ��� ,
#define LEX_LEFTBRACE '{' // ������� ��� {
#define LEX_BRACELET '}' // ������� ��� }
#define LEX_LEFTHESIS '(' // ������� ��� (
#define LEX_RIGHTHESIS ')' // ������� ��� )
#define LEX_PLUS 'v' // ������� ��� +
#define LEX_MINUS 'v' // ������� ��� -
#define LEX_STAR 'v' // ������� ��� *
#define LEX_DIRSLASH 'v' // ������� ��� /
#include <vector>

namespace LT // ������� ������
{
	struct Entry // ������ ������� ������
	{
		char lexema[LEXEMA_FIXSIZE];  // �������
		int sn; // ����� ������ � �������� ������
		int idxTI; // ������ � ������� ��������������� ��� LT_TI_NULLIDX
	};

	struct LexTable // ��������� ������� ������
	{
		int maxsize; // ������� ������� ������ < LT_MAXSIZE
		int size; // ������� ������ ������� ������ < maxsize
		std::vector<Entry> table; // ������ ����� ������� ������

		LexTable(  // ������� ������� ������
			int ms // ������� ������� ������ < LT_MAXSIZE
		);

		void Add(
			Entry entry // ������ ������� ������
		);

		Entry GetEntry(// �������� ������ ������� ������
			int n
		);

		void Delete(); // ������� ������� ������ (���������� ������)
	};
};

