#include <float.h>

namespace Varparm {

	int ivarparm(int n, ...)
	{
		int mul = 1;
		int* p = &n;
		if (n == 0)
			return 0;
		for (int i = 1; i < n + 1; i++)
			mul *= *(p + i);
		return mul;
	}

	int svarparm(short n, ...) {
		int max = 0;
		int* p = (int*)(&n);
		if (n == 0)
			return 0;
		for (int i = 1; i < n + 1; i++)
		{
			if (*(p + i) > max)
				max = *(p + i);
		}
		return max;
	}

	double fvarparm(float n, ...) {
		double sum = (double)n;
		double* ptr = (double*)(&n + 1);
		if (n == 0)
			return 0;
		if (n == FLT_MAX) return 0;
		for (int i = 0; ptr[i] != (double)FLT_MAX; i++) {
			sum += ptr[i];
		}
		return sum;
	}

	double dvarparm(double n, ...) {
		double sum = n;
		double* ptr = &n + 1;
		if (n == 0)
			return 0;
		if (n == DBL_MAX) return 0;
		for (int i = 0; ptr[i] != DBL_MAX; i++)
			sum += ptr[i];
		return sum;
	}
}