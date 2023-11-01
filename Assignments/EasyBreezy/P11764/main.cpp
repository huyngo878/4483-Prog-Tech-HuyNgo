#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        int walls[50];
        for (int i = 0; i < N; i++) {
            cin >> walls[i];
        }

        int high_jumps = 0, low_jumps = 0;

        for (int i = 0; i < N - 1; i++) {
            if (walls[i] < walls[i+1]) {
                high_jumps++;
            } else if (walls[i] > walls[i+1]) {
                low_jumps++;
            }
        }

        cout << "Case " << t << ": " << high_jumps << " " << low_jumps << endl;
    }

    return 0;
}
