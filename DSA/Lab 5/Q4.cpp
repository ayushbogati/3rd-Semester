#include <iostream>
using namespace std;

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case: 0th Fibonacci number is 0
    }
    if (n == 1) {
        return 1; // Base case: 1st Fibonacci number is 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int n;

    cout << "Enter the position (n) to find the nth Fibonacci number: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci series is not defined for negative numbers.\n";
    } else {
        cout << "The " << n << "th Fibonacci number is " << fibonacci(n) << ".\n";
    }

    return 0;
}

