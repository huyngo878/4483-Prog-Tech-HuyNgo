#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool isGreen(int duration, int t)
{
    int cycle_time = t % (2 * duration);
    return cycle_time < (duration - 5);
}

int main()
{
    while (true)
    {
        vector<int> lights;
        int cycle;

        // Read until a zero is encountered from the file.
        while (cin >> cycle && cycle)
        {
            lights.push_back(cycle);
        }

        // Exit if three consecutive zeros.
        if (lights.size() == 0)
            break;

        int minCycle = *min_element(lights.begin(), lights.end());

        bool found = false;
        for (int t = 2 * minCycle; t <= 18000 && !found; ++t)
        {
            bool allGreen = true;
            for (int cycle : lights)
            {
                if (!isGreen(cycle, t))
                {
                    allGreen = false;
                    break;
                }
            }
            if (allGreen)
            {
                found = true;
                int hours = t / 3600;
                int minutes = (t % 3600) / 60;
                int seconds = t % 60;
                printf("%02d:%02d:%02d\n", hours, minutes, seconds);
            }
        }

        if (!found)
        {
            cout << "Signals fail to synchronise in 5 hours" << endl;
        }
    }

    return 0;
}
