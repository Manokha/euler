#include <iostream>
#include <cmath>
#include <boost/math/special_functions/prime.hpp>
#include <boost/multiprecision/gmp.hpp>

using namespace std;


int main (int argc, char ** argv) {
	// Start at 10000th prime number (boost's prime starts at 2)
	unsigned long int checked_natural = boost::math::prime(9999);
	unsigned long int max_check;
	unsigned long int primes[200000] = { 0 };
	unsigned long int prime_index = 1;
	unsigned long int i;
	boost::multiprecision::mpz_int sum = 0;
	
	for (i = 0; i < 10000; i++)
		sum += boost::math::prime(i);

	primes[0] = boost::math::prime(9999);

	while (checked_natural < 2000000) {
		// Skip even numbers
		checked_natural += 2;
		max_check = sqrt(checked_natural);

		// No need to check against non prime numbers
		for (i = 1; i < 9999; i++)
			if (checked_natural % boost::math::prime(i) == 0)
				goto next;
			else if (boost::math::prime(i) > max_check)
				goto add;

		for (i = 0; i < prime_index && primes[i] < max_check; i++)
			if (checked_natural % primes[i] == 0)
				goto next;
			else if (primes[i] > max_check)
				goto add;

		for (i = primes[prime_index-1]; i < max_check; i++)
			if (checked_natural % i == 0)
				goto next;

		add:
		sum += checked_natural;
		primes[prime_index++] = checked_natural;

		next:
		;
	}

	cout << sum << endl;

	return 0;
}
