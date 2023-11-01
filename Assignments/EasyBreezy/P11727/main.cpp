#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int salaries[3];

        // Read salaries
        for (int i = 0; i < 3; i++) {
            cin >> salaries[i];
        }

        // Sort the salaries
        sort(salaries, salaries + 3);
      
        cout << "Case " << t << ": " << salaries[1] << endl;
    }

    return 0;
}
