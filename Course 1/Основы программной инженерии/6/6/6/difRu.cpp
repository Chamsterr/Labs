#include "difRu.h"

void difRu() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char title_letter, lower_letter, code_title_letter, code_lower_letter;
	int variant, difference;

	cout << "Введите с клавиатуры заглавную букву русского алфавита" << endl;
	cin >> title_letter;

	lower_letter = tolower(title_letter);

	code_title_letter = char(title_letter);
	code_lower_letter = char(lower_letter);

	difference = abs(code_title_letter - code_lower_letter);
	cout << "разницы значений кодов букв русского алфавита в прописном и строчном написании равно = " << difference << endl;
}
