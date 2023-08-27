#include "Dictionary.h"
#include <iostream>
#include <cstring>
using namespace Dictionary;
using namespace std;

Instance Dictionary::Create(const char* name, int size) //создать экземпляр словаря
{
	Instance NewDict;
	if (strlen(name) > ENTRYNAMEMAXSIZE) //превышен размер имени словаря
	{
		throw THROW01;
	}
	else
	{
		strcpy_s(NewDict.name, name);
	}
	if (NewDict.maxsize < size) //превышен размер максимальной емкости словаря
	{
		throw THROW02;
	}
	else
	{
		NewDict.size = size;
	}
	NewDict.dictionary = new Entry[size]; //выделение памяти в куче, т.е. динамической памяти
	return NewDict;
}
void Dictionary::addEntry(Instance& inst, Entry ed) //добавить элемент словаря
{
	int cnt = inst.cnt;
	if (cnt >= inst.size) //переполнение словаря
	{
		throw THROW03;
	}
	else
	{
		inst.dictionary[cnt] = ed;
	}
	for (int i = 0; i < cnt; i++)
	{
		if (inst.dictionary[i].id == ed.id) throw THROW04; //дублирование индентификатора
	}
	inst.cnt++;
}
void Dictionary::DelEntry(Instance& inst, int id) //удалить элемент словаря
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			isFound = true;
			for (int j = i; j < inst.cnt; j++)
			{
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.cnt--;
			break;
		}
	}
	if (!isFound) throw THROW06; //не найден элемент
}
Entry Dictionary::GetEntry(Instance& inst, int id) //получить элемент словаря
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			cout << inst.dictionary[i].name << endl;
			return inst.dictionary[i];
		}
	}
	if (!isFound) throw THROW05; //не найден элемент
}
void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) //изменить элемент словаря
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			for (int j = i + 1; j < inst.cnt; j++)
			{
				if (new_ed.id == inst.dictionary[j].id) throw THROW08; //дублирование идентификатора
			}
			isFound = true;

			inst.dictionary[i].id = new_ed.id;
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			break;
		}
		else if (new_ed.id == inst.dictionary[i].id) throw THROW08; //дублирование идентификатора
	}
	if (!isFound)
	{
		throw THROW07; //не найден элемент
	}
}
void Dictionary::Print(Instance& d) //печать
{
	cout << endl << endl;
	for (int i = 0; i < d.cnt; i++)
	{
		cout << "ID = " << d.dictionary[i].id
			<< "\nФамилия " << d.dictionary[i].name << endl << endl;
	}
}
void Dictionary::Delete(Instance& inst) //удаление
{
	delete[] inst.dictionary;
}
