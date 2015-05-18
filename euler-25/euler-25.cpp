#include <iostream>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;


int main (int argc, char ** argv) {
	mpz_int previous = 1;
	mpz_int current = 1;
	mpz_int next = 2;
	mpz_int index = 2;
	mpz_int checker = 10;

	for (unsigned int i = 1; i < 999; i++)
		checker *= 10;

	while (current < checker) {
		index++;
		previous = current;
		current = next;
		next = previous + current;
	}

	cout << index << endl;

	return 0;
}
