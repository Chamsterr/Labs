#include <iostream>
#include <windows.h>
#include "stdafx.h"
#include "D:\Labs\КПО\07._Static_library\SE_Lab07S\SE_Lab07L\Dictionary.h"
#pragma	comment(lib, "D:\\Labs\\КПО\\07._Static_library\\SE_Lab07S\\Debug\\SE_Lab07L.lib")
using namespace std;
using namespace Dictionary;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
#if ((defined(TEST_CREATE_02) && defined(TEST_CREATE_01)) || (defined(TEST_ADDENTRY_03) && (defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) ||  (defined(TEST_ADDENTRY_04) && (defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) || (defined(TEST_GETENTRY_05) && (defined(TEST_ADDENTRY_04) || defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) || (defined(TEST_DELENTRY_06) && (defined(TEST_GETENTRY_05) || defined(TEST_ADDENTRY_04) || defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) || (defined(TEST_UPDENTRY_07) && (defined(TEST_DELENTRY_06) || defined(TEST_GETENTRY_05) || defined(TEST_ADDENTRY_04) || defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) || (defined(TEST_UPDENTRY_87) && (defined(TEST_UPDENTRY_07) || defined(TEST_DELENTRY_06) || defined(TEST_GETENTRY_05) || defined(TEST_ADDENTRY_04) || defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))))
#error Превышенно количество макросов
#endif
	try
	{
#if defined(TEST_CREATE_01) //превышен размер имени словаря
		Instance d1 = Create("оченьоченьоченьбольноеимядлясловаря", 5);
#elif defined(TEST_CREATE_02) //превышен размер максимальной емкости словаря
		Instance d1 = Create("Преподaватели", 100000);
#else 
		Instance d1 = Create("Преподaватели", 5); //создание словаря
#endif
		Entry e1 = { 1, "Гладкий" }, //элементы словаря
			e2 = { 2, "Чайковский" },
			e3 = { 3, "Наркевич" },
			e4 = { 4, "Белодед" },
#if defined(TEST_ADDENTRY_04) //дублирование индентификатора
			e5 = { 2, "Мущук" };
#else 
			e5 = { 5, "Мущук" };
#endif
		addEntry(d1, e1); //добавление элемента в словарь
		addEntry(d1, e2);
		addEntry(d1, e3);
		addEntry(d1, e4);
		addEntry(d1, e5);
#if defined(TEST_ADDENTRY_03) //переполнение словаря
		addEntry(d1, e5);
#endif

#if defined(TEST_GETENTRY_05) //GetEntry: не найден элемент
		Entry ex2 = GetEntry(d1, 4000);
#else
		Entry ex2 = GetEntry(d1, 4); //найти элемент в словаре по id 4
#endif
#if defined(TEST_DELENTRY_06) //DelEntry: не найден элемент
		DelEntry(d1, 20000);
#else
		DelEntry(d1, 2); //удалить элемент в словаре по id
#endif
#if defined(TEST_UPDENTRY_08) //UpdEntry: дублирование идентификатора
		Entry newentry1 = { 1, "Гурин" };
#else 
		Entry newentry1 = { 6, "Гурин" };  //элемент словаря
#endif
#if defined(TEST_UPDENTRY_07) //UpdEntry: не найден элемент
		UpdEntry(d1, 30000, newentry1);
#else
		UpdEntry(d1, 3, newentry1); //заменить эл-т словаря по id
#endif
		Print(d1); //распечатать эл-ты словаря

		Instance d2 = Create("Студенты", 5);
		Entry s1 = { 1, "Трубач" },
			s2 = { 2, "Песецкий" },
			s3 = { 3, "Гайков" };
		addEntry(d2, s1);
		addEntry(d2, s2);
		addEntry(d2, s3);

		Entry newentry3 = { 3, "Денисенко" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	system("pause");
}
