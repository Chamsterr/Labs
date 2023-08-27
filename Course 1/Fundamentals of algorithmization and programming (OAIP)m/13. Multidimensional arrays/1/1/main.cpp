#include <iostream> 
void main()
{
	const int c_i = 3;
	const int c_j = 2;
	int a[c_i][c_j] = { { 10,2 },{ 30,4 },{ 5,6 } };
	int i, j, max = 0, min = 1000, max_i, max_j, min_j, min_i;
	for (i = 0; i < c_i; i++){
		for (j = 0; j < c_j; j++){
			if (max < a[i][j]) {
				max = a[i][j];
				max_i = i;
				max_j = j;
			}
			if (min > a[i][j]) {
				min = a[i][j];
				min_i = i;
				min_j = j;
			}
		}
	}
	a[min_i][min_j] = max;
	a[max_i][max_j] = min;

	for (i = 0; i < c_i; i++)
		for (j = 0; j < c_j; j++)
			std::cout << "\n a[" << i << "," << j << "] =" << a[i][j];
}