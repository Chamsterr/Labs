#include <iostream>
using namespace std;

int fib(int);

void main()
{
    setlocale(LC_ALL, "Ru");
    int N;
    cout << "Введите число N: ";
    cin >> N;
    unsigned int start_time = clock();
    cout << fib(N-1) <<endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Расчетное время рекурсией: " << search_time << "мс";
}
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}