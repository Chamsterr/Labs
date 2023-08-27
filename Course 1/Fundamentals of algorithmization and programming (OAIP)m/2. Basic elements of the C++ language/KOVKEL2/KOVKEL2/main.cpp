#include <iostream>
void main()
{
	float x = 1.4, m = 6, z = 0.05 * pow(10,-5), y, w;
	y = sqrt(1 + x) - cos(2/m);
	w = 0.6 * z - 2 * exp(-2 * y * m);
	std::cout << "y=" << y <<" ";
	std::cout << "w=" << w;
	
}