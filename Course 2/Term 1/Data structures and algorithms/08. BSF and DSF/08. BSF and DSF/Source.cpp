#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

void BSF() {
	int array_test[][3] = { {2, 5}, {1, 7, 8}, {8}, {6, 9}, {1, 6}, {4, 5, 9}, {2, 8}, {2, 3, 7}, {4, 6, 10}, {10}, {9} };
	/*int array_test[][3] = { {2, 4}, {1, 6, 7}, {7}, {1, 5}, {4, 8}, {2, 7}, {2, 3, 6}, {5} };*/
	int start = 1;

	int* begin = std::begin(array_test[0]);
	int* end = std::end(array_test[0]);

	deque<int> visited;
	queue<int> queue;

	for (int* ptr = begin; ptr != end; ptr++){
		if (*ptr != 0)
			queue.push(*ptr);
	}

	visited.push_back(start - 1);

	while (!queue.empty()) 
	{
		int edge = queue.front();
		queue.pop();

		deque<int>::iterator where = find(visited.begin(), visited.end(), edge - 1);

		if (where == visited.end()) {
			visited.push_back(edge - 1);

			begin = std::begin(array_test[edge - 1]);
			end = std::end(array_test[edge - 1]);

			for (int* ptr = begin; ptr != end; ptr++){
				if (*ptr != 0)
					queue.push(*ptr);
			}
		}

	}

	while (!visited.empty()) {
		cout << visited.front() + 1;
		visited.pop_front();
	}
}

void DSF() {
	int array_test[][3] = { {2, 5}, {1, 7, 8}, {8}, {6, 9}, {1, 6}, {4, 5, 9}, {2, 8}, {2, 3, 7}, {4, 6, 10}, {10}, {9} };
	/*int array_test[][3] = { {2, 4}, {1, 6, 7}, {7}, {1, 5}, {4, 8}, {2, 7}, {2, 3, 6}, {5} };*/
	int start = 1;

	int* begin = std::begin(array_test[0]);
	int* end = std::end(array_test[0]);

	deque<int> visited;
	stack<int> stack;

	for (int* ptr = begin; ptr != end; ptr++){
		if (*ptr != 0)
			stack.push(*ptr);
	}

	visited.push_back(start - 1);

	while (!stack.empty())
	{
		int edge = stack.top();
		stack.pop();

		deque<int>::iterator where = find(visited.begin(), visited.end(), edge - 1);

		if (where == visited.end()) {
			visited.push_back(edge - 1);

			begin = std::begin(array_test[edge - 1]);
			end = std::end(array_test[edge - 1]);

			for (int* ptr = begin; ptr != end; ptr++){
				if (*ptr != 0)
					stack.push(*ptr);
			}
		}

	}

	while (!visited.empty()) {
		cout << visited.front() + 1;
		visited.pop_front();
	}
}

void main() {
	BSF();
	cout << endl;
	DSF();
}