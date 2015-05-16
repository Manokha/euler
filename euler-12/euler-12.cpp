#include <iostream>
#include <cmath>

using namespace std;


int main (int argc, char ** argv) {
	unsigned long long int current = 28;
	unsigned long long int x = 7;
	unsigned long long int divisor;
	unsigned long long int count;
	unsigned long long int max;

	do {
		current += ++x;
		// Start with 1 and current in count
		count = 2;
		max = sqrt(current);

		if (current % max == 0)
			count++;

		for (divisor = 2; divisor < max; divisor++)
			if (current % divisor == 0)
				count += 2;

	} while (count < 500);

	cout << x << endl;
	cout << current << endl;

	return 0;
}
