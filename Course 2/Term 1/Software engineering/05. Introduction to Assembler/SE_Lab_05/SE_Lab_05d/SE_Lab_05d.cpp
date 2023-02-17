#include <iostream>

extern "C" {
	int raiser(int a, int b) {
		return pow(a, b);
	}
	int module(int a) {
		return abs(a);
	}
	void __stdcall print(char* value)
	{
		std::cout << value << "\n";
	}

	void __stdcall printint(int value)
	{
		std::cout << value << "\n";
	}
}
