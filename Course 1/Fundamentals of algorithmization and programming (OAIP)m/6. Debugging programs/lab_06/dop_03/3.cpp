#include <iostream>
using namespace std;

void main() {
	int s = 30 , n;

	for (int y = 1; y < 10; ++y) 
		{
		for (int x = 0; x < 10; ++x) 
		{
			if (s == 2*(x+ y) && x != y)
			{	
				n = x * 1000  + y * 100 + y * 10 + x;
				if (n % 7 == 0 && n % 2 == 0 && n % 11 == 0) 
				{
					cout << n << endl;
					cout << endl;
				}
			}
		}
	}
	
}
