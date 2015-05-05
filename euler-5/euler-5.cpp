#include <iostream>

using namespace std;


int main (int argc, char ** argv) {
	// No need to check previous numbers: they already don't valid with numbers from 1 to 10.
	unsigned int current = 2520;
	unsigned int denominator;

	while (true) {
		// 1 is always true
		// If evenly divisible by 20 then 10, 5, 4 and 2 are true
		// If evenly divisible by 18 then 9, 6 and 3 are true
		// If evenly divisible by 16 then 8 is true
		// If evenly divisible by 14 then 7 is true
		// Thus we can go from 20 to 11.
		for (denominator = 20; denominator > 10; denominator--)
			if (current % denominator != 0)
				goto next;

		cout << current << endl;
		return 0;

		next:
		current += 20;
	}

	return 1;
}
