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
		std::cout << "Цепочка " << fst1.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst1.string << " не распознана" << std::endl;

	if (FST::execute(fst2))
		std::cout << "Цепочка " << fst2.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst2.string << " не распознана" << std::endl;

	if (FST::execute(fst3))
		std::cout << "Цепочка " << fst3.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst3.string << " не распознана" << std::endl;

	if (FST::execute(fst4))
		std::cout << "Цепочка " << fst3.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst3.string << " не распознана" << std::endl;

	if (FST::execute(fst5))
		std::cout << "Цепочка " << fst5.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst5.string << " не распознана" << std::endl;

	if (FST::execute(fst6))
		std::cout << "Цепочка " << fst6.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst6.string << " не распознана" << std::endl;

	if (FST::execute(fst7))
		std::cout << "Цепочка " << fst7.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst7.string << " не распознана" << std::endl;

	if (FST::execute(fst8))
		std::cout << "Цепочка " << fst8.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst8.string << " не распознана" << std::endl;
	if (FST::execute(fst9))
		std::cout << "Цепочка " << fst9.string << " распознана" << std::endl;
	else
		std::cout << "Цепочка " << fst9.string << " не распознана" << std::endl;
	return 0;
}