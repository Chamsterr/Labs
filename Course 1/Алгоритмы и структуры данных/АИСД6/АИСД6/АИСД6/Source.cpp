#include <iostream>
#include <string>

#define INT_MAX 32767

using namespace std;

struct Node {
	string FIO;
	int phone_number;
	struct Node* next = nullptr, * prev = nullptr, * end = nullptr, * head = nullptr;
};

struct Hash_table {
	int key;
	struct Node *Hash_node;
	struct Hash_table* nextHT = nullptr, * prevHT = nullptr, * endHT = nullptr, * headHT = nullptr;
};

int hash_function(int key, int table_size) {
	return key / table_size;
}

Hash_table* Creat_Hash_Node() {
	Hash_table* newHT = new Hash_table;
	newHT->endHT = newHT;
	newHT->headHT = newHT;
	return newHT;
}

Node* Add_Hash_Node_Element(int phone_number, string FIO) {
	Node* temp = new Node;
	if(!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		exit;
	}
	temp->phone_number = phone_number;
	temp->FIO = FIO;
	temp->next = NULL;
	temp->prev = NULL;
	temp->head = temp;
	temp->end = temp;
	return temp;
}

void Add_HT_Element(int key, Hash_table** HT_Head, Hash_table** HT_End, Node* element){
	Node* ND = element;
	Hash_table* HT = *HT_Head;
	//создание первого элемента
	if (HT_Head == NULL) {
		HT = Creat_Hash_Node();
		HT->key = key;
		HT->Hash_node = element;
	}
	else {
		//если существует хотя бы одна структура Hash_table

		//сравнение с существующими элементами
		for (;;) {
			//если существует элемент с таким же ключом соединяем с узлом
			if (key == HT->key) {

			}
			else if (HT->nextHT == NULL) {
				//если не существует таких же элементов создаём новый

			}
			HT = HT->nextHT;
		}
	}
}
void input_function(int table_size, Hash_table** headHT, Hash_table** endHT) {


	int key;
	int input_number;
	string input_FIO;

	do {
		cout << "Input Number" << endl;
		cin >> input_number;
	} while (input_number > INT_MAX || input_number < 0);

	cout << "Input FIO" << endl;
	cin >> input_FIO;

	key = hash_function(input_number, table_size);

	Add_HT_Element(key, headHT, endHT, Add_Hash_Node_Element(input_number, input_FIO));
	
	cout << input_FIO << " " << input_number << " " << key;
}

int main() {
	Hash_table* headHT = NULL;
	Hash_table* endHT = NULL;
	int table_size = 16;
	input_function(table_size, &headHT, &endHT);

}