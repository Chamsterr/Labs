#pragma once
#define ID_MAXSIZE 5 // максимальное кол-во символов в идентификаторе
#define TI_MAXSIZE 4096 // макс кол-во строк в таблице идентификаторов
#define TI_INT_DEFAULT 0x00000000 // значение по умолчанию для integer
#define TI_STR_DEFAULT 0x00 // значение по умолчанию для string
#define TI_NULLIDX 0xffffffff // нет элемента таблицы идентификаторов
#define TI_STR_MAXSIZE 255 
#include <vector>

namespace IT
{
	enum IDDATATYPE {INT=1, STR=2}; // типы данных идентификаторов: integer, string
	enum IDTYPE { V=1, F=2, P=3, L=3}; // типы идентификаторов: переменная, функция, параметр, литер

	struct Entry
	{
		int idxfirstLE; // индекс первой строки в таблице лексем
		char id[ID_MAXSIZE]; // идентификаторов (автоматически усекается до ID_MAXSIZE)
		IDDATATYPE iddatatype; // тип данных
		IDTYPE idtype; // тип идентификаторов
		union
		{
			int vint; // значение integer
			struct
			{
				char len; // кол-во символов в string
				char str[TI_STR_MAXSIZE - 1]; // символы string
			} vstr[TI_STR_MAXSIZE];
		} value; // значение идентификатора

	};

	struct  IdTable // экземпрляр таблицы идентификаторов
	{
		int maxsize; // емкость таблицы идентификаторов < TI_MAXSIZE
		int n; // текущий размер таблицы идентификаторов < maxsize
		std::vector<Entry> table; //массив строк таблицы идентификатор

		IdTable(int ms);

		void Add(Entry entry);

		Entry GetEntry(int n);

		int IsId(char id[ID_MAXSIZE]);

		void Delete();
	};
}