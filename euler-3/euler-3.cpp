#include <iostream>
#include <cmath>

using namespace std;


int main (int argc, char ** argv) {
	unsigned long long int num = 600851475143;
	unsigned long long int factor;
	unsigned long long int big_factor;
	/* Using max_factor = square root as both factor and division result
	 * are checked when modulo is 0 */
	unsigned long long int max_factor = sqrt(num);
	unsigned long long int largest = 1;
	unsigned long long int prime_check;
	unsigned long long int max_prime_check;

	// Starting at 3 with increments of 2 as even factors won't give a modulo of 0
	for (factor = 3; factor < max_factor; factor += 2) {
		if (num % factor != 0)
			continue;

		max_prime_check = factor / 2;

		// even factors have been filtered
		for (prime_check = 3; prime_check <= max_prime_check; prime_check += 2)
			if (factor % prime_check == 0)
				goto check_big_factor;

		if (factor > largest)
			largest = factor;

		check_big_factor:
		big_factor = num / factor;
		max_prime_check = big_factor / 2;

		// even factors have been filtered
		for (prime_check = 3; prime_check <= max_prime_check; prime_check += 2)
			if (big_factor % prime_check == 0)
				goto next_factor;

		largest = big_factor;

		next_factor:
		;
	}

	cout << largest << endl;

	return 0;
}
