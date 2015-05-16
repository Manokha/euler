#include <iostream>
#include <boost/multiprecision/gmp.hpp>

using namespace std;


int main (int argc, char ** argv) {
	boost::multiprecision::mpz_int number = 1;
	boost::multiprecision::mpz_int result = 0;

	for (unsigned int i = 2; i <= 100; i++)
		number *= i;

	while (number > 0) {
		result += number % 10;
		number /= 10;
	}

	cout << result << endl;

	return 0;
}
