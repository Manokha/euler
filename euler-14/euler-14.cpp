#include <iostream>

using namespace std;


int main (int argc, char ** argv) {
	unsigned long long int current;
	unsigned long long int x;
	unsigned long long int count;
	unsigned long long int max_count = 10;
	unsigned long long int result = 13;

	for (x = 14; x < 1000000; x++) {
		count = 0;
		current = x;

		while (current > 1) {
			count++;
			
			if (current % 2 == 0)
				current /= 2;
			else
				current = current * 3 + 1;
		}

		if (count > max_count) {
			max_count = count;
			result = x;
		}
	}

	cout << result << " (" << max_count << ")" << endl;

	return 0;
}
