/*3. Write a program to solve non-linear equation using Secant method. Your program should read  an initial guess from 
keyboard and display the followings if the solution is obtained: 
a. Estimated root of the equation 
b. Functional value at calculated root 
c. Required number of iterations*/

#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
    return x * x - 4;
}
void secant(double x0, double x1, int max_iterations, double tolerance) {
    int iteration = 0;
    double x2;
    while (iteration < max_iterations) {
        double f0 = func(x0);
        double f1 = func(x1);
        if (f1 - f0 == 0) {
            cout << "Zero difference in function values, no solution found." << endl;
            return;
        }
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        if (fabs(x2 - x1) < tolerance) {
            cout << "Converged to the root: " << x2 << endl;
            cout << "Functional value at the root: " << func(x2) << endl;
            cout << "Number of iterations: " << iteration + 1 << endl;
            return;
        }
        x0 = x1;
        x1 = x2;
        iteration++;
    }
    cout << "Maximum iterations reached. Approximate root: " << x2 << endl;
    cout << "Functional value at the approximate root: " << func(x2) << endl;
    cout << "Number of iterations: " << max_iterations << endl;
}
int main() {
    double x0, x1;
    int max_iterations;
    double tolerance;
    cout << "Enter the first initial guess (x0): ";
    cin >> x0;
    cout << "Enter the second initial guess (x1): ";
    cin >> x1;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iterations;
    cout << "Enter the desired tolerance: ";
    cin >> tolerance;
    secant(x0, x1, max_iterations, tolerance);
    return 0;
}
