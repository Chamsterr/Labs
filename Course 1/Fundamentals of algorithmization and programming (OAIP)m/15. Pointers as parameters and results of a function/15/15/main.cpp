#include <iostream>

float finction_one(float x) {
	x = exp(x) + 2;
	return x;
}

float finction_one_shtrih(float x) {
	x = exp(x);
	return x;
}

float Method_Porabol(float a, float b, float n) {
	using namespace std;
	float h, s1 = 0, s2 = 0, i = 1, x, z;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	do {
		s2 = s2 + finction_one(x);
		x = x + h;
		s1 = s1 + finction_one(x);
		x = x + h;
		i = i + 1;
	} while (i > n);
	z = (h / 3) * (finction_one(a) + 4 * finction_one((a + h)) + 4 * s1 + 2 * s2 + finction_one(b));
	cout << z << endl;
	return z;
}

float Method_Trapecii(float a, float b, float n) {
	using namespace std;
	float h, x, s, z;
	h = (b - a) / n; x = a; s = 0;
	do {
		s = s + h * (finction_one(x) + finction_one(x + h)) / 2;
		x = x + h;
	} while (x < (b - h));
	z = x;
	cout << z << endl;
	return z;
}

float Method_Kasatelnoi(float a, float b, float n, float e) {
	using namespace std;
	float x1, x;
	if (finction_one(a) * finction_one_shtrih(a) > 0) {
		x1 = a;
	}
	else {
		x1 = b;
	}
	do {
		x = x1;
		x1 = x - (finction_one(x) / finction_one_shtrih(x));
	} while (abs(x1 - x) < e);
	x1 = sqrt(x1);
	cout << x1 << endl;
	return x1;
}

float Method_Dihotomii(float a, float b, float n, float e) {
	using namespace std;
	float x;
	do {
		x = (a + b) / 2;
		if (finction_one(x) * finction_one(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (abs(a - b) > 2 * e);
	cout << x << endl;
	return x;
}

float main() {
	using namespace std;
	float a, b, n = 200, e = 0.0001;
	cout << "cin a = ";
	cin >> a;
	cout << "cin b = ";
	cin >> b;
	(*Method_Porabol)(a, b, n);
	(*Method_Trapecii)(a, b, n);
	(*Method_Kasatelnoi)(a, b, n, e);
	float (*functOne)(float a, float b, float n, float e);
	functOne = Method_Dihotomii;
	functOne(a, b, n, e);
}