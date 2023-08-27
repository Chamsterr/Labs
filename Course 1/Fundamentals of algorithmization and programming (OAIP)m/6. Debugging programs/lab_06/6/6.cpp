#include <iostream>
#include <list>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	list <int> chisla{1};
	int m, n, counter, counter2 = 0, s = 1, x;
	cout << "¬ведите m=";
	cin >> m;
	cout << "¬ведите n=";
	cin >> n;

	if (0 == sqrt(m) - int(sqrt(m))); {
		for (counter = 2; counter < n; counter++) {
			s = s + counter;
			chisla.push_front(counter);
			if (s == sqrt(m)) {
				for (auto i = chisla.begin(); i != chisla.end(); ++i) cout << *i << endl;
				return 0;

			}

		}cout << "„исло " << m  << " нельз€ разложить таким способом";
	}
		

}