#include <iostream>
#include <vector>

struct number {
	int var;
	int l;

	number(int i) {
		var = i;
		l = 0;
	}
};


std::vector <number> subsequence(std::vector <number> sequence, int N) {
	int max = 0;
	sequence[0].l = 1;
	for (int i = 1; i < sequence.size(); i++) {
		for (int j = i-1; j >= 0; j--) {
			if (sequence[j].var < sequence[i].var && sequence[j].l > sequence[i].l) {
				max = sequence[j].l + 1;
				sequence[i].l = max;
			}
		}
	}
	for (int i = 0; i < sequence.size(); i++) {
		std::cout << sequence[i].var << " - " << sequence[i].l << std::endl;
	}
	
	if (N <= max) {
		int counter = N;
		for (int j = sequence.size() - 1; j >= 0; j--) {
			if (sequence[j].l == counter){
				std::cout << sequence[j].var << " ";
				counter--;
			}
		}
	}
	else {
		std::cout << "No";
	}

	return sequence;
}

void main() {
	std::vector <number> sequence = { 5, 10, 6, 12, 3, 24, 7, 8 };
	int N;

	std::cout << "N = ";
	std::cin >> N;

	subsequence(sequence, N);
}