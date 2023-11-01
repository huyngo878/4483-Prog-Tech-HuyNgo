#include <iostream>
#include <string>
using namespace std;

int main() {
    int I;
    while (cin >> I && I) {
        int count = 0;
        string binary = "";
        
        for (int temp = I; temp; temp >>= 1) {
            if (temp & 1) {
                count++;
                binary = "1" + binary;
            } else {
                binary = "0" + binary;
            }
        }

        cout << "The parity of " << binary << " is " << count << " (mod 2)." << endl;
    }

    return 0;
}
