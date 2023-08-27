#include <iostream>
void main()
{
	float k = 4, x = 2 * pow(10, -4), a = 8.1, n = 3, t, u;
	t = 2 * k / a + log(2 + x);
	u = sqrt(k - 1) / (t + 1);
	std::cout << "t=" << t << " ";
	std::cout << "u=" << u << " ";
}