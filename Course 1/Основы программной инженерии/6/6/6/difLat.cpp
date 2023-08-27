#include<iostream>
#include "difLat.h"

void difLat() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	char title_letter, lower_letter, code_title_letter, code_lower_letter;
	int variant, difference;

	cout << "Введите с клавиатуры заглавную букву латинского алфавита" << endl;
	cin >> title_letter;

	lower_letter = tolower(title_letter);

	code_lower_letter = int(lower_letter);
	code_title_letter = int(title_letter);

	difference = code_lower_letter - code_title_letter;
	cout << "разницы значений кодов букв латинского алфавита в прописном и строчном написании равно = " << difference << endl;
}