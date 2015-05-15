#include <iostream>
#include <cmath>

using namespace std;


int main (int argc, char ** argv) {
	unsigned int a, b, c;

	for (a = 1; a < 333; a++) {
		for (b = a + 1; b < (1000 - a) / 2; b++) {
			c = 1000 - a - b;

			if (a*a + b*b == c*c) {
				cout << a << "² + " << b << "² = " << c << "²" << endl;
				cout << a*a << " + " << b*b << " = " << c*c << endl;
				cout << a << " + " << b << " + " << c << " = 1000" << endl;
				cout << "Answer: " << a*b*c << endl;
				return 0;
			}
		}
	}

	return 1;
}
