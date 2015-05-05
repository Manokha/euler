#include <iostream>

using namespace std;


bool is_palindrome(unsigned int value) {
	for (unsigned int digit = 100000; digit >= 1000; digit /= 10)
		if (((value / digit) % 10) != ((value / (100000 / digit)) % 10))
			return false;
	return true;	
}

int main (int argc, char ** argv) {
	unsigned int first;
	unsigned int second;
	unsigned int result;
	unsigned int palindrome = 0;
	
	for (first = 999; first >= 100; first--) {
		for (second = 999; second >= 100; second--) {
			result = first * second;

			if (result < palindrome)
				break;

			if (is_palindrome(result)) {
				palindrome = result;
				break;
			}
		}
	}

	cout << palindrome << endl;

	return 0;
}
