#include <iostream>
void main()
{
	float i = -6,  z = 1.5 * pow(10, -6), x = 4.5, d, f;
	d = tan(-x * i)/ sqrt(x-z);
	f = sin(2*d)/d;
	std::cout << "d=" << d << " ";
	std::cout << "f=" << f << " ";
}