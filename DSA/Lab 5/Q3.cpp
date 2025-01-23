#include <iostream>
using namespace std;

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    }
    return n * factorial(n - 1); // Recursive case
}

int main() {
    int num;
    
    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers.\n";
    } else {
        cout << "The factorial of " << num << " is " << factorial(num) << ".\n";
    }

    return 0;
}
