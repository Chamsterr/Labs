#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#define IM 1000

int matrix[8][8] = { { IM,  2,  IM,  8,  2,  IM,  IM, IM },
				 { 2,  IM,  3, 10,  5,  IM,  IM, IM },
				 { IM,  3,  IM,  IM, 12,  IM,  IM, 7 },
				 { 8, 10,  IM,  IM, 14,  3,  1, IM },
				 { 2,  5, 12, 14,  IM, 11,  4, 8 },
				 { IM,  IM,  IM,  3, 11,  IM,  6, IM },
				 { IM,  IM,  IM,  1,  4,  6,  IM, 9 },
				 { IM,  IM,  7,  IM,  8,  IM,  9, IM } };

int Kruskal() {
	std::vector <int> history;
	std::vector <int> min_distanses;

	do{
		int minimum = IM;
		int next_node = IM;
		int next_i;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				auto iter = std::find(history.begin(), history.end(), i);
				
				if (minimum > matrix[i][j] && iter == history.end()) {
					minimum = matrix[i][j];
					next_node = j;
					next_i = i;
				}
			}
		}
		
		if (next_node != IM)
		{
			min_distanses.push_back(minimum);
			matrix[next_node][next_i] = IM;
			matrix[next_i][next_node] = IM;
			history.push_back(next_i);
		}
	}while (min_distanses.size() != 7);
	int sum = 0;

	for (auto i = 0; i < min_distanses.size(); i++) {
		sum += min_distanses[i];
	}

	return sum;
}
int Prim() {
	std::vector <int> history;
	std::vector <int> min_distanses;

	int chosen_node;

	do
	{
		std::cout << "Выберите вершину: ";
		std::cin >> chosen_node;
	} while (chosen_node >= 0 and chosen_node >= 8);


	history.push_back(chosen_node - 1);

	while (history.size() != 8) {
		int minimum = IM;
		int next_node = IM;
		for (int i = 0; i < history.size(); i++) {
			for (int j = 0; j < 8; j++) {
				auto iter = std::find(history.begin(), history.end(), j);
				if (minimum > matrix[history[i]][j] && iter == history.end()) {
					minimum = matrix[history[i]][j];
					next_node = j;
				}
			}
		}
		min_distanses.push_back(minimum);
		if (next_node != IM)
			history.push_back(next_node);
	}
	int sum = 0;
	for (auto i = 0; i < min_distanses.size(); i++) {
		sum += min_distanses[i];
	}

	return sum;
}

void main() {
	setlocale(LC_ALL, "Ru");
	std::cout << Prim() << std::endl;
	std::cout << Kruskal() << std::endl;
}