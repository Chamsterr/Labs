#include <iostream>
#include <string>
#include <vector>
#include <regex>
struct product {
	std::string name;
	int weight;
	int price;

	product(std::string n, int w, int p) {
		name = n;
		weight = w;
		price = p;
	}
};

void main() {
	setlocale(LC_ALL, "Ru");
	int backpack_weight;
	std::vector <product> products;


	std::cout << "Введите вес рюкзака: ";
	std::cin >> backpack_weight;

	products.push_back(product{ "Гитара", 1, 1500 });
	products.push_back(product{ "Магнитофон", 4, 3000 });
	products.push_back(product{ "Ноутбук", 3, 2000 });

	/*while (true) {
		std::string name;
		int weight;
		int price;

		std::cout << "Название товара: ";
		std::cin >> name;
		if (name == "q") {
			break;
		}

		std::cout << "Вес товара: ";
		std::cin >> weight;

		std::cout << "Цена товара: ";
		std::cin >> price;

		products.push_back(product { name, weight, price });
	}*/

	std::vector <std::vector <int>> table;
	for(int i = 0; i < products.size() + 1; i++){
		std::vector <int> col;
		for (int j = 0; j < backpack_weight; j++) {
			col.push_back(0);
		}
		table.push_back(col);
	}
	
	for (int i = products[0].weight - 1; i <= backpack_weight - 1; i++) {
		table[1][i] = products[0].price;
	}
	for (int i = 2; i < table.size(); i++) {
		for (int j = 0; j < backpack_weight; j++) {
			int remaining_weight = j + 1  - products[i - 1].weight;
			if (remaining_weight > 0)
				table[i][j] = std::max(table[i - 1][j], products[i - 1].price + table[i - 1][remaining_weight -1]);
			else if (remaining_weight < 0) {
				table[i][j] = table[i - 1][j];
			}
			else {
				table[i][j] = std::max(table[i - 1][j], products[i - 1].price);
			}
		}
	}
	
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < backpack_weight ; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::vector <int> col;


	std::vector <product> answers;
	for (int i = products.size() ; i > 0; i--) {
		if (table[i][backpack_weight - 1] != table[i - 1][backpack_weight - 1])
		{
			answers.push_back(products[i -1]);
			backpack_weight -= products[i -1].weight;
		}
	}

	for (int i = 0; i < answers.size(); i++) {
		std::cout << answers[i].name << " ";
	}
}