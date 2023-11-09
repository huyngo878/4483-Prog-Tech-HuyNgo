#include <iostream>
#include <string>
using namespace std;

int main() {
  int x;
  string word;
  int iter = 1;

  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> word;
    if (word.length() == 3) {
      if ((word[0] == 't' && word[1] == 'w') ||
          (word[0] == 't' && word[2] == 'o') ||
          ((word[1] == 'w' && word[2] == 'o') && (word[0] != 'o'))) {
        cout << "2" << endl;
        iter++;
      } else if ((word[0] == 'o' && word[1] == 'n') ||
                 (word[0] == 'o' && word[2] == 'e') ||
                 (word[1] == 'n' && word[2] == 'e')) {
        cout << "1" << endl;
        iter++;
      }
    } else if (word.length() > 3) {
      if (word[0] == 't') {
        cout << '3' << endl;
        iter++;
      }
    }
  }

  return 0;
}
