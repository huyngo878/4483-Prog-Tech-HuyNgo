#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int C, N;
    cin >> C;

    for (int i = 0; i < C; i++) {
        cin >> N;

        vector<int> grades(N);
        double sum = 0;

        for (int j = 0; j < N; j++) {
            cin >> grades[j];
            sum += grades[j];
        }

        double avg = sum / N;
        int above_avg_count = 0;

        for (int grade : grades) {
            if (grade > avg) {
                above_avg_count++;
            }
        }

        // Compute the percentage of students with grades above average
        double percentage = (double)above_avg_count / N * 100;
        cout << fixed << setprecision(3) << percentage << "%" << endl;
    }

    return 0;
}
