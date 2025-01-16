/*1. Write a program to solve non-linear equation using Half Interval method. Your program should read an initial 
guess from keyboard and display the followings if the solution is obtained: 
a. Estimated root of the equation 
b. Functional value at calculated root 
c. Required number of iterations*/

#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
    return exp(-x) - x;  // f(x) = e^(-x) - x
}
void bisection(double initial_guess, int max_iterations) {
    double a = initial_guess - 1.0; 
    double b = initial_guess + 1.0;
    if (func(a) * func(b) >= 0) {
        cout << "Invalid interval. The function must have opposite signs at the endpoints." << endl;
        return;
    }
    int iteration = 0;
    double c = a;
    while ((b - a) / 2.0 > 1e-6 && iteration < max_iterations) {
        c = (a + b) / 2.0;
        
        if (func(c) == 0.0) {
            break;
        }
        else if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        iteration++;
    }
    cout << "Estimated root: " << c << endl;
    cout << "Functional value at the estimated root: " << func(c) << endl;
    cout << "Number of iterations: " << iteration << endl;
}
int main() {
    double initial_guess;
    int max_iterations;
    cout << "Enter an initial guess for the root: ";
    cin >> initial_guess;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iterations;
    bisection(initial_guess, max_iterations);
    return 0;
}
