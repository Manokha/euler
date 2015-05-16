#include <iostream>

using namespace std;

//                          0  1  2  3  4  5  6  7  8  9
unsigned int digits[9] =     { 3, 3, 5, 4, 4, 3, 5, 5, 4 };
unsigned int teens[10] =  { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
unsigned int decades[8] =       { 6, 6, 5, 5, 5, 7, 6, 6 };

int main (int argc, char ** argv) {
	unsigned int below_ten = 0;
	unsigned int below_hundred = 0;
	unsigned int sum = 0;
	unsigned int i;

	// 1..9
	for (i = 0; i < 9; i++)
		sum += digits[i];

	below_ten = sum;

	// 10..19
	for (i = 0; i < 10; i++)
		sum += teens[i];

	// 20..99
	for (i = 0; i < 8; i++)
		sum += decades[i] * 10 + below_ten;

	below_hundred = sum;

	// 100..999
	for (i = 0; i < 9; i++) {
		//                     hundred and
		sum += digits[i] * 100 + 700 + 297 + below_hundred;
	}

	// 1000
	sum += 11;

	cout << sum << endl;

	return 0;
}
