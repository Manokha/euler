#include <iostream>
#include <vector>
#include <list>

using namespace std;


vector<unsigned int> results;

void permute(unsigned int head, vector<unsigned int> digits) {
	if (digits.size() == 1)
		results.push_back(head * 10 + digits[0]);
	else {
		for (auto i = 0; i < digits.size(); i++) {
			auto digits_left(digits);
			unsigned int new_head = head * 10 + digits_left[i];
			digits_left.erase(digits_left.begin() + i);

			permute(new_head, digits_left);
		}
	}
}

int main (int argc, char ** argv) {
	vector<unsigned int> digits;
	for (unsigned int i = 0; i < 10; i++)
		digits.push_back(i);

	permute(0, digits);

	cout << results[999999] << endl;

	return 0;
}
