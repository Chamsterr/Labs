#include <iostream>
using namespace std;

typedef bool operation_type;
typedef int value;
typedef int date;

typedef int day;
typedef int month;
typedef int year;

const char* month_arr[] = { "Января", "Февраля", "Марта", "Апреля", "Мая", "Июня", "Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря" };

struct Date
{
	day dd;
	month mm;
	year yyyy;
};

struct History_of_opetations
{
	operation_type o_t;
	value v;
	Date Date;
};

ostream& operator<< (ostream& out, History_of_opetations h_o) {
	if (h_o.o_t == 1)
		out << "Пополнение: " << h_o.v << "руб. " << h_o.Date.dd << " " << *(month_arr + h_o.Date.mm - 1)<< " " << h_o.Date.yyyy << " года" << endl;
	else
		out << "Снятие: " << h_o.v << "руб. " << h_o.Date.dd << " " << *(month_arr + h_o.Date.mm - 1) << " " << h_o.Date.yyyy << " года" << endl;

	return out;
}

int operator+ (int a, History_of_opetations h_o) {
	return a + h_o;
}

int count_balance(History_of_opetations arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if(arr[i].o_t == 1)
			sum = sum + arr[i].v;
		else
			sum = sum - arr[i].v;
	}
	return sum;
}
void main() {
	setlocale(LC_ALL, "Ru");
	const int n = 3;
	History_of_opetations arr[n] = { { 1, 500, 28, 12, 2004}, { 0, 250, 29, 03, 2005 }, { 1, 50, 21, 04, 2005 } };

	cout << "Ваши операции: (1:" << n << ")" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << "Общий баланс: " << count_balance(arr, n);

}

