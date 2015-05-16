#include <iostream>

using namespace std;

unsigned int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main (int argc, char ** argv) {
	unsigned int year = 1900;
	unsigned int month = 0;
	unsigned int day_of_week = 0;
	unsigned int result = 0;

	while (year < 2000 || month < 11) {
		day_of_week += days_in_month[month];
		
		if (month == 1 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			day_of_week++;

		day_of_week = day_of_week % 7;

		if (day_of_week == 6 && year > 1900)
			result++;

		month++;
		if (month == 12) {
			month = 0;
			year++;
		}
	}

	cout << result << endl;

	return 0;
}
