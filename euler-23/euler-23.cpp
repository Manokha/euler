#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int main (int argc, char ** argv) {
	unsigned long long int result = 0;
	unsigned long long int n, divisor, max, current;
	vector<unsigned long long int> abundants;
	set<unsigned long long int> sums;
	auto it = abundants.begin();
	auto it2 = abundants.begin();

	for (n = 12; n < 28123; n++) {
		max = sqrt(n);
		current = 1;
		if (n % max == 0 && n / max == max) {
			current += max;
			max--;
		}

		for (divisor = 2; divisor <= max; divisor++)
			if (n % divisor == 0)
				current += divisor + n / divisor;

		if (current > n)
			abundants.push_back(n);
	}

	for (it = abundants.begin(); it != abundants.end(); it++)
		for (it2 = it; it2 != abundants.end() && ((*it) + (*it2) <= 28123); it2++)
			sums.insert((*it) + (*it2));


	// It has been proven that all even numbers > 46 are the sum of twi abundant numbers in at least one way.
	// http://oeis.org/wiki/Abundant_numbers
	for (n = 1; n < 28123; n++)
		if (n < *(sums.begin()))
			result += n;
		else
			sums.erase(sums.begin());


	cout << result << endl;

	return 0;
}
