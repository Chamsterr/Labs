#include <iostream>
#include <limits.h>
#include <float.h>

using namespace std;
int sum(int x, int y) { return x + y; };
int(*f) (int, int);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	bool run = true, flag = false;

	int n = 7, X = 9 + n, Y = 10 + n, Z = 11 + n;
	float S = 1.0 + n;

	char letter = 'O', letter_ru = 'Î';
	wchar_t letter_w = 'K', letter_w_ru = 'Ê';

	short num_s = X, num_s_m = -X;
	short min_s = 0x8001, max_s = 0x7fff;
	unsigned short min = 0x0, max = 0xffff;

	int num_int = Y, num_int_m = -Y;
	int min_i = 0x80000001, max_i = 0x7fffffff;
	unsigned int min_u_i = 0x0, max_u_i = 0xffffffff;

	long num_long = Z, num_long_m = -Z;
	long mix_l = 0x80000001, max_l = 0x7fffffff;
	unsigned int min_u_l = 0x0, max_u_l = 0xffffffff;

	float num_f = S, num_f_m = -S;
	long mix_f = 0x80000001, max_f = 0x7fffffff;
	unsigned int min_u_f = 0x0, max_u_f = 0xffffffff;



	float a1 = S / 0;
	cout << "a1 - " << a1 << endl;
	float a2 = -S / 0;
	cout << "a2 - " << a2 << endl;
	float a3 = sqrt(-2.0);
	cout << "a3 - " << a3 << endl;

	char c01 = 'k';
	wchar_t wc01 = 'k';
	short s01 = 17;
	int i01 = 170;
	float f01 = 18.5;
	double d01 = 18.0005;
	char* yc = &c01;
	wchar_t* ywc = &wc01;
	short* ys = &s01;
	int* yi = &i01;
	float* yf = &f01;
	double* yd = &d01;

	char* yc1 = yc + 3;
	wchar_t* ywc1 = ywc + 3;
	short* ys1 = ys + 3;
	int* yi1 = yi + 3;
	float* yf1 = yf + 3;
	double* yd1 = yd + 3;
	f = sum;
	int i21 = f(17, 13);

}