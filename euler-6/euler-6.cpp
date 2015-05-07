#include <iostream>

using namespace std;


// Sum of squares: f(x) = f(x-1) + x^2
// Square of the sum: f(x) = f(x-1) + x^3
// Difference: f(x) = f(x-1) + x^3 - x^2
template <unsigned long long int n>
struct diff {
	enum { value = n*n*n - n*n + diff<n-1>::value };
};

template<>
struct diff<1> {
	enum { value = 0 };
};


int main (int argc, char ** argv) {
	cout << diff<100>::value << endl;

	return 0;
}
