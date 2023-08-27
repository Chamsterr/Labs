#include <iostream> 
void main()
{
	using namespace std;
	const int N = 6, M = 6;
	int sum = 0, nmax = 10, nmin = -10;
	int A[N][M] = { { 4, 3 , 5, - 5, 6, 7 },{ 3, 2, 5, 3, 4, 1},{ 2, 6, -6, 3, -2, 5 }, { 1, 2, 1, 3, 2, 5 }, {2, 1, 1, 3, 1, 4 }, { 1, 6, 4, 3, 1, 5 } };
	int i = 0, j = 0;
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << " " << endl;
	}
	i = 0, j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (A[i][j] <= 0) {
				for (j = 0; j < M; j++) {
					sum += A[i][j];
				}
			}
		}
	}
	cout << "sum = " << sum;
}