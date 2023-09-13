#include <iostream>
using namespace std;

int main() {
  int x = 22;
  cout << x << ' ';
  while (x != 1) {
    if ((x % 2) == 1) {
      x = (3 * x) + 1;
    } else {
      x = x / 2;
    }
    cout << x << ' ';
  }

  return 0;
}
