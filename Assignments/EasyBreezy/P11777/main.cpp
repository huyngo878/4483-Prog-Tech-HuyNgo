#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int Term1, Term2, Final, Attendance, CT1, CT2, CT3;
        cin >> Term1 >> Term2 >> Final >> Attendance >> CT1 >> CT2 >> CT3;

        // Find average of best 2 class tests
        int tests[3] = {CT1, CT2, CT3};
        sort(tests, tests + 3);
        int avg_class_test = (tests[1] + tests[2]) / 2;

        int total = Term1 + Term2 + Final + Attendance + avg_class_test;
        
        char grade;
        if (total >= 90) grade = 'A';
        else if (total >= 80) grade = 'B';
        else if (total >= 70) grade = 'C';
        else if (total >= 60) grade = 'D';
        else grade = 'F';

        cout << "Case " << t << ": " << grade << endl;
    }

    return 0;
}
