#include <iostream>

// We'll be checking the units place of both numbers first, 
// then the tens place, then the hundreds place, and so on.
// For each place, if there's a carry from the previous operation, we include that in our sum.
// If the sum of digits in the current position exceeds 9, then a carry will be generated.

int count_carries(int a, int b) {
    int carry = 0;
    int carry_count = 0;

    while (a > 0 || b > 0) {
        int sum = carry + (a % 10) + (b % 10);
        if (sum >= 10) {
            carry_count++;
            carry = sum / 10;
        } else {
            carry = 0;
        }
        a /= 10;
        b /= 10;
    }

    return carry_count;
}

int main() {
    int a, b;
    while (true) {
        std::cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }

        int result = count_carries(a, b);
        if (result == 0) {
            std::cout << "No carry operation." << std::endl;
        } else if (result == 1) {
            std::cout << "1 carry operation." << std::endl;
        } else {
            std::cout << result << " carry operations." << std::endl;
        }
    }
    return 0;
}