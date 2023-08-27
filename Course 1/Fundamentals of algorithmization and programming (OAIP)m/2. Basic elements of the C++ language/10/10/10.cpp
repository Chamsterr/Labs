#include <iostream>
void main()
{
	float z = 1.7, a = 4 * pow(10, -8), m = 3, n = 3, y, s;
	y = (z + log(z)) / (exp(-3) + sqrt(a));
	s = (1 + m * n) / log(1 + z);
	std::cout << y << " ";
	std::cout << s;

}