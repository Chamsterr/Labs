#include <iostream>
#include "FST.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Ru");
	
	FST::FST fst1(
		(char*)"abbh", 
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	FST::FST fst2(
		(char*)"abbbh",
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	FST::FST fst3(
		(char*)"abbbbh",
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	FST::FST fst4(
		(char*)"abbbbbh",
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	FST::FST fst5(
		(char*)"abbbbbbbh",
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	FST::FST fst6(
		(char*)"abcdlbh",
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	FST::FST fst7(
		(char*)"abcfgbh",
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	FST::FST fst8(
		(char*)"abbbbbbbbb",
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	FST::FST fst9(
		(char*)"babcfgbh",
		10,
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('b', 2)),
		FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('d', 4), FST::RELATION('f', 6)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('e', 5), FST::RELATION('b', 8)),
		FST::NODE(1, FST::RELATION('g', 7)),
		FST::NODE(3, FST::RELATION('l', 2), FST::RELATION('g', 7), FST::RELATION('b', 8)),
		FST::NODE(2, FST::RELATION('b', 8), FST::RELATION('h', 9)),
		FST::NODE()
	);

	if (FST::execute(fst1))
		std::cout << "������� " << fst1.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst1.string << " �� ����������" << std::endl;

	if (FST::execute(fst2))
		std::cout << "������� " << fst2.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst2.string << " �� ����������" << std::endl;

	if (FST::execute(fst3))
		std::cout << "������� " << fst3.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst3.string << " �� ����������" << std::endl;

	if (FST::execute(fst4))
		std::cout << "������� " << fst3.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst3.string << " �� ����������" << std::endl;

	if (FST::execute(fst5))
		std::cout << "������� " << fst5.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst5.string << " �� ����������" << std::endl;

	if (FST::execute(fst6))
		std::cout << "������� " << fst6.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst6.string << " �� ����������" << std::endl;

	if (FST::execute(fst7))
		std::cout << "������� " << fst7.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst7.string << " �� ����������" << std::endl;

	if (FST::execute(fst8))
		std::cout << "������� " << fst8.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst8.string << " �� ����������" << std::endl;
	if (FST::execute(fst9))
		std::cout << "������� " << fst9.string << " ����������" << std::endl;
	else
		std::cout << "������� " << fst9.string << " �� ����������" << std::endl;
	return 0;
}