#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;


int main (int argc, char ** argv) {
	list<string> names;
	char buffer[20];
	unsigned int position = 0,
		     result = 0,
		     current = 0;
	ifstream f("names.txt");

	while (!f.eof()) {
		// ignore first double quote
		f.ignore(1);
		// get until double quote
		f.getline(buffer, 20, '"');
		names.push_back(buffer);
		// ignore comma
		f.ignore(1);
	}

	names.sort();

	for (auto it = names.begin(); it != names.end(); it++) {
		position++;
		current = 0;
		
		for (auto cit = (*it).cbegin(); cit != (*it).cend(); cit++)
			current += (*cit) - 64;

		result += current * position;
	}

	cout << result << endl;

	return 0;
}
