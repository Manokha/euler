#include <iostream>

using namespace std;


int main (int argc, char ** argv) {
	unsigned long long int grid[21][21];
	unsigned int x, y;
	grid[0][0] = 1;

	// borders
	for (x = 0; x < 21; x++) {
		grid[0][x] = 1;
		grid[x][0] = 1;
	}

	// step by step, from borders to center
	for (x = 1; x < 21; x++) {
		grid[x][x] = grid[x-1][x] + grid[x][x-1];

		for (y = x+1; y < 21; y++) {
			grid[x][y] = grid[x-1][y] + grid[x][y-1];
			grid[y][x] = grid[y-1][x] + grid[y][x-1];
		}
	}

	cout << grid[20][20] << endl;

	return 0;
}
