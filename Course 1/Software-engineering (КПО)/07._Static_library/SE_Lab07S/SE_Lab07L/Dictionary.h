#pragma once
#define DICTNAMEMAXSIZE		20		//максимальный размер имени словар€
#define DICTMAXSIZE			100		//макс.Ємкость словар€
#define ENTRYNAMEMAXSIZE	30		//макс.длина имени в словаре
#define THROW01 "Create: превышен размер имени словар€"
#define THROW02 "Create: превышен размер максимальной емкости словар€"
#define THROW03 "AddEntry: переполнение словар€"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary
{
	struct Entry //элемент словар€
	{
		int id;
		char name[ENTRYNAMEMAXSIZE];
	};
	struct Instance //экземпл€р словар€
	{
		char name[ENTRYNAMEMAXSIZE];
		int maxsize = DICTMAXSIZE;
		int size;
		int cnt = 0;
		Entry* dictionary;
	};
	Instance Create  //создать словарь
	(
		const char* name,
		int size
	);
	void addEntry //добавить элемент в словарь
	(
		Instance& ints,
		Entry ed
	);
	void DelEntry( //удалить элемент словар€
		Instance& inst,
		int id
	);
	void UpdEntry //изменить элемент словар€
	(
		Instance& ints,
		int id,
		Entry new_ed
	);
	Entry GetEntry( //получить элемент словар€ по id
		Instance& inst,
		int id
	);
	void Print(Instance& d);
	void Delete(Instance& d);
};