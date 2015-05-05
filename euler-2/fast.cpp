#include <iostream>

using namespace std;

int main(int argc, char ** argv) {
	unsigned long int previous = 1;
	unsigned long int current = 2;
	unsigned long int next = 3;
	unsigned long int sum = 0;
	int i = 0;

	while (current < 4000000) {
		sum += current;
		
		// fibonacci sequence is even every three terms.
		previous = next + current;
		current = next + previous;
		next = previous + current;
	}

	cout << sum << endl;

	return 0;
}
