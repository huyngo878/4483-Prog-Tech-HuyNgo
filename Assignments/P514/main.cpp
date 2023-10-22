#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;

    while (cin >> n, n) {
        int target;
        while (cin >> target, target) {
            cin.ignore();
            vector<int> targets = {target};
            targets.resize(n);

            for (int i = 1; i < n; ++i) cin >> targets[i];

            stack<int> station;
            int next = 1;
            bool possible = true;
            
            for (int i = 0; i < n; ++i) {
                target = targets[i];
                if (next <= target) {
                    while (next <= target) station.push(next++);
                }
                if (station.top() == target) station.pop();
                else possible = false;
            }

            if (possible) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << '\n';
    }

    return 0;
}
