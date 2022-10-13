#include <iostream>
#include <string>
#include <stack>
#include <map>

#define poping_operation_in_result(stack) char operation = stack.top(); stack.pop(); result_str += operation;

using namespace std;

string PolishNotation(string str)
{
	string result_str;
	stack <char> operations;
	map <char, int> operations_priority = {
		{'(', 1},
		{')', 1},
		{'+', 2},
		{'-', 2},
		{'*', 3},
		{'/', 3}
	};

	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	for (int i = 0; i < str.length(); i++) {
		if (!operations_priority[str[i]])
			result_str += str[i];
		else {
			if ((operations.size() == 0 || str[i] == '('))
				operations.push(str[i]);
			else if (operations.size() && str[i] == ')') {
				while (operations.size() && operations.top() != '(') {
					poping_operation_in_result(operations);
				}
				operations.pop();
			}
			else {
				while (operations.size() != 0 && (operations_priority[operations.top()] >= operations_priority[str[i]])){
					poping_operation_in_result(operations);
				}
				operations.push(str[i]);
			}
		}
	}
	while (operations.size()) {
		poping_operation_in_result(operations);
	}

	return result_str;
}
void main()
{
	setlocale(LC_ALL, "Ru");
	string expression;

	cout << "¬ведите выражение: ";

	getline(cin, expression);

	cout << expression << " -- > "<< PolishNotation(expression) << endl;

	cout << "a+b/(c+с)*(g/(l-q/l)) + a --> " << PolishNotation("a+b/(c+с)*(g/(l-q/l)) + a") << endl; //a b c / g q / * +
	cout << "(a + c / (a + c / (a + c)))* (a + c) --> " << PolishNotation("(a + c / (a + c / (a + c)))* (a + c)") << endl; //a c a c a c + / + / + a c + *
	cout << "(a+c)*2+2 --> " << PolishNotation("(a+c)*2+2") << endl; // a c + 2 * 2 +
	cout << "2*(a+c)-2*(2+q)*p+2 --> " << PolishNotation("2*(a+c)-2*(2+q)*p+2") << endl; // 2 a c + * 2 2 q + * p * - 2 +
	cout << "q+w+e+r+t*y/s+1/(p+g) --> " << PolishNotation("q+w+e+r+t*y/s+1/(p+g)") << endl; // q w + e + r + t y * s / + 1 p g + / +
	cout << "(q-w+e*r+t*y-s*k/(p+g))/z --> " << PolishNotation("(q-w+e*r+t*y-s*k/(p+g))/z") << endl; // q w - e r * + t y * + s k * p g + / - z /
	cout << "x + (y * z + x) * z --> " << PolishNotation("(x + (y * z + x) * z)") << endl;
}