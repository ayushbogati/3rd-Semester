#include <iostream>
using namespace std;

// Function to calculate GCD using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a; // Base case: GCD of a and 0 is a
    }
    return gcd(b, a % b); // Recursive case
}

int main() {
    int num1, num2;

    cout << "Enter two numbers to find their GCD: ";
    cin >> num1 >> num2;

    if (num1 < 0 || num2 < 0) {
        cout << "GCD is not defined for negative numbers.\n";
    } else {
        cout << "The GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << ".\n";
    }

    return 0;
}
