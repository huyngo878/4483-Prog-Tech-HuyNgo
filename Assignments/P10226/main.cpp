#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // ignore the newline character after the number of test cases
    string line;
    getline(cin, line); // read the blank line between test cases number and the actual data

    while (t--)
    {
        map<string, int> treeCount;
        int totalTrees = 0;

        while (getline(cin, line) && !line.empty())
        {
            treeCount[line]++;
            totalTrees++;
        }

        for (const auto &pair : treeCount)
        {
            cout << fixed << setprecision(4);
            cout << pair.first << " " << pair.second * 100.0 / totalTrees << '\n';
        }

        if (t > 0)
            cout << '\n'; // print a blank line between test cases
    }

    return 0;
}
