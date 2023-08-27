#include <iostream>
using namespace std;
int day, month, year;
int arr_days[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char* month_arr[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};

void split_date(int date) {
	int delta_for_day = 1000000, delta_for_month_year = 10000;
	day = date / delta_for_day;
	month = date / delta_for_month_year - day * 100;
	year = date - (date / delta_for_month_year) * delta_for_month_year;
}
void match_month_day(int month){
	cout << month << " месяц это - " << *(month_arr + month - 1) << endl;
}
bool leap_year(int year) {
	if (year % 4 == 0)
		return true;
	else
		return false;
}
int serial_number(int day, int month, int year) {
	int serial = 0;
	for (int i = 0; (i + 1) < month; i++)
		serial = serial + arr_days[i];
	if (month > 2 && leap_year(year))
		return serial + day + 1;
	else
		return serial + day;
}
int near_br_day(int day, int month, int year) {
	int day_br = 28, month_br = 3;
	if (month == month_br && day == day_br)
		return 0;
	else if (month > month_br)
		return 365 - (serial_number(day, month, year + 1) - serial_number(day_br, month_br, year + 1));
	else if (month == month_br && day > day_br) {
		if (day > day_br && leap_year(year + 1))
			return 366 - abs(day - day_br);
		else
			return 365 - abs(day - day_br);
	}
	else
		return serial_number(day_br, month_br, year) - serial_number(day, month, year);
}
bool is_correct_date(int year) {
	if (day == 29 && leap_year(year))
		return true;
	if (day > arr_days[month - 1])
		return false;
	if (month > 12)
		return false;
}
int programmer_day(int year) {
	if (leap_year(year))
		return 1209 * 10000 + year;
	else
		return 1309 * 10000 + year;
}

void main() {
	setlocale(LC_ALL, "RUS");
	int date;
	cout << "Введите дату (ДДММГГГГ): ";
	cin >> date;
	split_date(date);
	if (is_correct_date(year) == false || year == 0 || date <= 1000000) {
		cout << "Некорректный ввод";
		exit(0);
	}
	if (leap_year(year))
		cout << year << " - високосный" << endl;
	else
		cout << year << " - не високосный" << endl;
	cout << serial_number(day, month, year) << " - порядковый номер дня" << endl;
	match_month_day(month);
	cout << near_br_day(day, month, year) << " - до ближайшего моего дня рождения (28.03)" << endl;
	cout << programmer_day(year) << " - день программиста в этом году" << endl;
}