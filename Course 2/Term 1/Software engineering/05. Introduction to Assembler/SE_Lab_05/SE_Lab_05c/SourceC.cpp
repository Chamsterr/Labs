#include <iostream>
#pragma comment(lib, "..\\Debug\\SE_Lab_05lib.lib")

extern "C"
{
	int __stdcall getmax(int*, int);
	int __stdcall getmin(int*, int);
};

int main(int argc, char** argv)
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, -123, 2, 0 };

	int max = getmax(x, 10);
	int min = getmin(x, 10);

	std::cout << max - min << std::endl;
	return 0;
}