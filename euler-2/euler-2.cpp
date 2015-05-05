#include <iostream>

using namespace std;

int main(int argc, char ** argv) {
	unsigned long int previous = 1;
	unsigned long int current = 2;
	unsigned long int next = 3;
	unsigned long int sum = 0;

	while (current < 4000000) {
		if (current % 2 == 0)
			sum += current;

		previous = current;
		current = next;
		next = previous + current;
	}

	cout << sum << endl;

	return 0;
}
