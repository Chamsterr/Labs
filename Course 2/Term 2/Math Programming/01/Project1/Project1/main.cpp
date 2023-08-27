#include "Auxil.h"                            // вспомогательные функции 
#include <iostream>
#include <ctime>
#include <locale>
#include <chrono>

#define  CYCLE  1000000                       // количество циклов  

int Fib(int i)
{
	int value = 0;
	if (i < 1) return 0;
	if (i == 1) return 1;
	return Fib(i - 1) + Fib(i - 2);
}

int task2()
{
	double  av1 = 0, av2 = 0;

	auxil::start();                          // старт генерации 
	auto start = std::chrono::steady_clock::now();
	Fib(26);
	auto end = std::chrono::steady_clock::now();                     // фиксация времени 

	std::cout << "\nпродолжительность (н.с):   " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count();
	std::cout << std::endl;
	system("pause");

	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");

	task2();
	system("pause");

	double  av1 = 0, av2 = 0;


	auxil::start();                          // старт генерации 
	auto start = std::chrono::steady_clock::now();
	for (long long i = 0; i < 1000000; i++)
	{
		av1 += (int)auxil::iget(-100, 100);
		av2 += auxil::dget(-100, 100);
	}
	auto end = std::chrono::steady_clock::now();                     // фиксация времени 

	std::cout << "количество циклов:         " << CYCLE;
	std::cout << "\nсреднее значение (int):    " << av1 / CYCLE;
	std::cout << "\nсреднее значение (double): " << av2 / CYCLE;
	std::cout << "\nпродолжительность (н.с):   " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count();
	std::cout << std::endl;
	system("pause");

	return 0;
}