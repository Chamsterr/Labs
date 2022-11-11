// Huffman's algorithm
#include <iostream>
#include <string>
#include <vector>

struct letter_with_counter {
	int counter;
	std::string letter;

	letter_with_counter(char l) {
		counter = 1;
		letter = l;
	}

	void add_lwc(letter_with_counter lwc) {
		counter += lwc.counter;
		letter += lwc.letter;
	}
};

std::vector<letter_with_counter> letters;

bool find(char letter) {
	for (int j = 0; j < letters.size(); j++) {
		if (letter == letters[j].letter[0]) {
			letters[j].counter++;
			return true;
		}
	}
	return false;
}

//Сортировка выбором не дает результат как в лекции, но это нормально))
//void sort() {
//	for (int i = 0; i < letters.size(); i++) {
//		for (int j = 0; j < letters.size(); j++) {
//			if (letters[i].counter > letters[j].counter) {
//				std::swap(letters[i], letters[j]);
//			}
//		}
//	}
//}

void sort() {
	for (int i = 0; i < letters.size(); i++) {
		int k = i;
		while (k > 0 and letters[k - 1].counter < letters[k].counter) {
			std::swap(letters[k - 1], letters[k]);
			k -= 1;
		}
	}
}

int Huffman(std::string expression) {
	letters.push_back(letter_with_counter(expression[0]));

	for (int i = 1; i < expression.size(); i++) {
		if (!find(expression[i]))
			letters.push_back(letter_with_counter(expression[i]));
	}
	
	sort();
	
	for (int i = 0; i < letters.size(); i++) {
		std::cout << letters[i].letter << " - " << letters[i].counter << std::endl;
	}

	while (letters.size() != 1) {
		letter_with_counter lwc1 = letters.back();
		letters.pop_back();

		letter_with_counter lwc2 = letters.back();
		letters.pop_back();

		lwc2.add_lwc(lwc1);
		letters.push_back(lwc2);

		sort();
		std::cout << "----------------------------" << std::endl;
		for (int i = 0; i < letters.size(); i++) {
			std::cout << letters[i].letter << " - " << letters[i].counter << std::endl;
		}
	}

	for (int i = 0; i < letters.size(); i++) {
		std::cout << letters[i].letter << " - " << letters[i].counter << std::endl;
	}
	return 0;
}

int main() {
	std::string expression;
	getline(std::cin, expression);
	Huffman(expression);
	return 0;
}
