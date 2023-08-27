#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
//2
auto lambda_func_true_or_false = [](auto x) {
	if (x < 0)
		return false;
	if ((int)x > 127)
		return false;
	else
		return true;
};

int main() {
	setlocale(LC_ALL, "Russian");
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10 };

	int target1 = 3;
	int num_items1 = count(v.begin(), v.end(), target1);
	cout << "Число: " << target1 << " количество " << num_items1 << '\n';

	int num_item3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	cout << "количество элементов кратных 3 " << num_item3 << '\n';
	cout << endl << "Лямбда, захват переменных" << endl;

	for (auto i : v)[i]() {if (i % 3 == 0) cout << i << " "; };

	cout << endl << " Лямбда с параметрами" << endl;

	for (auto i : v)[](auto i) {if (i % 3 == 0) cout << i << " "; }(i);

	cout << endl << " Лямбда без параметров" << endl;

	for (auto i : v)[i] {if (i % 3 == 0)cout << i << " "; }();

	cout << endl;
	//1
	float z = 5;

	if ([](auto y) {if (y >= 0) { return true; } else { return false; }}(z))
		cout << "true\n";
	else
		cout << "false\n";

	//2
	cout << lambda_func_true_or_false(7) << endl;
	cout << lambda_func_true_or_false(-7) << endl;
	cout << lambda_func_true_or_false('a') << endl;
	cout << lambda_func_true_or_false('п') << endl;

	//3 
	char alpha2[60] = "asdfv", betta2[] = "rgws";
	[](auto& x, auto& c) { strcat_s(x, c); cout << x << endl; }(alpha2, betta2);

	//4
	[](auto& x, auto& c) { if (strlen(x) > strlen(c)) { cout << x; } else { cout << c; }} (alpha2, betta2);

	return 0;
}