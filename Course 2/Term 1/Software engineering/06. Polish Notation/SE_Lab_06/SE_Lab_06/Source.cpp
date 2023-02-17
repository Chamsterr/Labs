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

	cout << "Введите выражение: ";

	getline(cin, expression);

	cout << expression << " -- > "<< PolishNotation(expression) << endl;

	cout << "i(i,i,i)vi; --> " << PolishNotation("i(i,i,i)vi;") << endl;
}