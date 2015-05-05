#include <iostream>

using namespace std;

int main(int argc, char ** argv) {
  unsigned long int result = 0;
  unsigned long int inc;

  for (inc = 3; inc < 1000; inc += 3)
    result += inc;

  for (inc = 5; inc < 1000; inc += 5)
    result += inc;

  for (inc = 15; inc < 1000; inc += 15)
    result -= inc;

  cout << result << endl;
  return 0;
}
