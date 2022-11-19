#include <iostream>
#include <string>
#include <vector>
#include <map>

struct letter_with_counter {
	int counter;
	std::string letter;
	std::string position = "";
	int left = -1;
	int right = -1;
	
	letter_with_counter(char l) {
		counter = 1;
		letter = l;
	}

	letter_with_counter(int x, std::string l) {
		counter = x;
		letter = l;
	}

	letter_with_counter add_lwc(letter_with_counter lwc) {
		letter_with_counter lwc_ = { counter, letter };
		lwc_.counter += lwc.counter;
		lwc_.letter += lwc.letter;
		return lwc_;
	}
};

std::vector<letter_with_counter> letters;
std::vector<letter_with_counter> all_nodes;
std::map <char, std::string> table_of_correspondence;


bool find(char letter) {
	for (int j = 0; j < letters.size(); j++) {
		if (letter == letters[j].letter[0]) {
			letters[j].counter++;
			return true;
		}
	}
	return false;
}

void sort() {
	for (int i = 0; i < letters.size(); i++) {
		int k = i;
		while (k > 0 and letters[k - 1].counter < letters[k].counter) {
			std::swap(letters[k - 1], letters[k]);
			k -= 1;
		}
	}
}

void print_lwc(std::vector<letter_with_counter> arr_ls) {
	for (int i = 0; i < arr_ls.size(); i++) {
		std::cout << arr_ls[i].letter << " - " << arr_ls[i].counter << std::endl;
	}
}

void change_child(int lwc, std::string zero_or_one) {
	if (all_nodes[lwc].right != -1) {
		change_child(all_nodes[lwc].left, zero_or_one);
		change_child(all_nodes[lwc].right, zero_or_one);
	}
	else{
		all_nodes[lwc].position = zero_or_one + all_nodes[lwc].position;
	}
}

int Huffman(std::string expression) {
	letters.push_back(letter_with_counter(expression[0]));

	for (int i = 1; i < expression.size(); i++) {
		if (!find(expression[i]))
			letters.push_back(letter_with_counter(expression[i]));
	}

	sort();

	std::cout << "-------------------------" << std::endl;
	print_lwc(letters);

	while (letters.size() != 1) {
		letter_with_counter lwc1 = letters.back();
		letters.pop_back();

		letter_with_counter lwc2 = letters.back();
		letters.pop_back();

		letter_with_counter lwc3 = lwc2.add_lwc(lwc1);

		all_nodes.push_back(lwc1);
		int inndex_lwc1 = all_nodes.size();

		all_nodes.push_back(lwc2);
		int inndex_lwc2 = all_nodes.size();

		lwc3.left = inndex_lwc1 - 1;
		lwc3.right = inndex_lwc2 - 1;

		change_child(lwc3.left, "0");
		change_child(lwc3.right, "1");

		letters.push_back(lwc3);

		sort();
		std::cout << "-------------------------" << std::endl;
		print_lwc(letters);
	}
	print_lwc(letters);
	std::cout << "-------------------------" << std::endl;

	for (int i = 0; i < all_nodes.size(); i++) {
		if (all_nodes[i].letter.length() == 1) {
			std::cout << all_nodes[i].letter << " - " << all_nodes[i].position << std::endl;
			table_of_correspondence[all_nodes[i].letter[0]]= all_nodes[i].position;
		}
	}

	std::string result = "";
	for (int i = 0; i < expression.length(); i++) {
		result += table_of_correspondence[expression[i]];
	}

	std::cout << "-------------------------" << std::endl;
	std::cout << "Expression:" << expression << std::endl;
	std::cout << "Result:" << result << std::endl;
	return 0;
}

int main() {
	std::string expression;
	getline(std::cin, expression);
	Huffman(expression);
	return 0;
}