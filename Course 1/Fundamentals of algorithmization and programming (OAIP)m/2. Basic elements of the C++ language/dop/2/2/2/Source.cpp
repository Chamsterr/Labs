#include <iostream>
void main()
{
	float n = 2, x = 1.3 * pow(10, -4), b = 0.12, z, y;
	z = 1/(x-1)+sin(x)-sqrt(n);
	y =(exp(-b) + 1) / 2*z;
	std::cout << "z=" << z << " ";
	std::cout << "y=" << y << " ";
}