#include <iostream>

//Функция, возвращающая сумму цифр
unsigned getSumOfDigits(unsigned x) {
    unsigned result = x % 10;
    while (x /= 10) {
        result += x % 10;
    }
    return result;
}

// Квадрат числа
unsigned sqr(const unsigned x) {
    return x * x;
}

int main()
{
    unsigned n = 0, m = 0;
    std::cin >> n >> m;
    for (unsigned i = 1; i < n; i++) {
        if (sqr(getSumOfDigits(i)) == m) {
            std::cout << i << ' ';
        }
    }
}