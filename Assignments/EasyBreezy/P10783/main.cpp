#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; 

    for (int t = 1; t <= T; t++) {
        int a, b, sum = 0;
        cin >> a >> b;

        // Make sure 'a' starts as odd. If it's even, increase by 1.
        if (a % 2 == 0) {
            a++;
        }
        // Sum up all odd numbers from 'a' to 'b'
        for (int i = a; i <= b; i += 2) {
            sum += i;
        }
        cout << "Case " << t << ": " << sum << endl;
    }

    return 0;
}
