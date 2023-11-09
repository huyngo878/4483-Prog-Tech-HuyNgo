#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, z, total;
  vector<int> age;

  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> y;
    for (int j = 0; j < y; j++) {
      cin >> z;
      age.push_back(z);
    }

    total = (age.size() / 2);
    cout << "Case " << (i + 1) << ": " << age.at(total) << endl;
    age.clear();
  }
  return 0;
}
