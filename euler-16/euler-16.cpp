#include <iostream>
#include <boost/multiprecision/gmp.hpp>

using namespace std;


int main (int argc, char ** argv) {
	boost::multiprecision::mpz_int number = 2;
	boost::multiprecision::mpz_int result = 0;

	for (unsigned int i = 1; i < 1000; i++)
		number *= 2;

	while (number > 0) {
		result += number % 10;
		number /= 10;
	}

	cout << result << endl;

	return 0;
}
