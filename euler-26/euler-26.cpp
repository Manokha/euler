#include <iostream>
#include <cmath>

using namespace std;

const unsigned int max_sequence = 100000;

int main (int argc, char ** argv) {
	unsigned int current;
	unsigned int digit;
	unsigned int sequence[max_sequence];
	unsigned int sequence_2[max_sequence];
	unsigned int sequence_pos = 0;
	unsigned int sequence_2_pos = 0;
	unsigned int sequence_start = 0;
	unsigned int max_found = 0;
	unsigned int max_number = 0;

	for (unsigned int i = 2; i <= 1000; i++) {
		current = 10;
		digit = i;
		sequence_pos = 0;
		sequence_2_pos = 0;
		sequence_start = 0;

		digit = current / i;
		current = (current % i) * 10;
		sequence[sequence_pos++] = digit;

		while (current != 0) {
			digit = current / i;
			current = (current % i) * 10;

			if (sequence_2_pos != 0) {
				if (sequence_2_pos + sequence_start >= sequence_pos) {
					if (digit == sequence[sequence_start]) {
						cout << "Number " << i << " : sequence of " << sequence_2_pos << endl;

						if (sequence_2_pos > max_found) {
							max_found = sequence_2_pos;
							max_number = i;
						}
						break;
					}
				}
				else if (digit == sequence[sequence_2_pos + sequence_start]) {
					sequence_2[sequence_2_pos++] = digit;
					goto next;
				}

				if (sequence_2_pos + sequence_pos + 1 >= max_sequence) {
					cout << "Skipping " << i << " : total sequence too long." << endl;
					break;
				}
				else {
					for (unsigned int copy_incr = 0; copy_incr < sequence_2_pos; copy_incr++)
						sequence[sequence_pos++] = sequence_2[copy_incr];

					sequence[sequence_pos++] = digit;
					sequence_2_pos = 0;
				}
			}
			else {
				for (unsigned int start_incr = 0; start_incr < sequence_pos; start_incr++) {
					if (digit == sequence[start_incr]) {
						sequence_2[sequence_2_pos++] = digit;
						sequence_start = start_incr;
						goto next;
					}
				}
				
				sequence[sequence_pos++] = digit;
			}

			next:
			;
			if (sequence_pos > max_sequence || sequence_2_pos > max_sequence) {
				cout << "Skipping " << i << " : sequence too long." << endl;
				break;
			}
		}
	}

	cout << "Max : " << max_number << " with a sequence of " << max_found << endl;

	return 0;
}
