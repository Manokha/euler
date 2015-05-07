#include <iostream>
#include <cstdlib>
#include <boost/math/special_functions/prime.hpp>

using namespace std;


int main (int argc, char ** argv) {
	// Start at 10000th prime number (boost's prime starts at 2)
	unsigned long int checked_natural = boost::math::prime(9999);
	
	while (true) {
		next:
		// Skip even numbers
		checked_natural += 2;

		// No need to check against non prime numbers
		for (unsigned int i = 1; i < 10000; i++)
			if (checked_natural % boost::math::prime(i) == 0)
				goto next;

		cout << checked_natural << endl;
		return 0;
	}

	return 1;
}
