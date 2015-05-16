#include <iostream>
#include <cmath>

using namespace std;


int main (int argc, char ** argv) {
	unsigned int results[10000] = { 0 };
	unsigned int n, divisor, max;
	unsigned int result = 0;

	for (n = 2; n < 10000; n++) {
		results[n] = 1;
		max = sqrt(n);

		if (n % max == 0)
			results[n] += max;

		for (divisor = 2; divisor < max; divisor++)
			if (n % divisor == 0)
				results[n] += divisor + n / divisor;
	}

	for (n = 1; n < 10000; n++)
		if (results[n] < 10000 && n != results[n] && n == results[results[n]])
			result += n;

	cout << result << endl;

	return 0;
}
