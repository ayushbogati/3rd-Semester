/*6. Compare various method for solving non-linear equation in terms of speed, accuracy and ease  of coding.*/

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

double f(double x) {
    return x*x - 4;
}

double df(double x) {
    return 2*x;
}

// Bisection Method
double bisection(double (*f)(double), double a, double b, double tol) {
    double c;
    while ((b - a) / 2.0 > tol) {
        c = (a + b) / 2.0;
        if (f(c) == 0.0) break;  // Root found
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }
    return (a + b) / 2.0;
}

// Newton-Raphson Method
double newtonRaphson(double (*f)(double), double (*df)(double), double x0, double tol) {
    double x = x0;
    while (fabs(f(x)) > tol) {
        x = x - f(x) / df(x);
    }
    return x;
}

// Secant Method
double secantMethod(double (*f)(double), double x0, double x1, double tol) {
    double x2;
    while (fabs(f(x1)) > tol) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }
    return x2;
}

int main() {
    double a = 0, b = 3;
    double x0 = 3;
    double tol = 1e-6;
    
    clock_t start = clock();
    double rootBisection = bisection(f, a, b, tol);
    clock_t end = clock();
    double bisectionTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    double rootNewton = newtonRaphson(f, df, x0, tol);
    end = clock();
    double newtonTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    double rootSecant = secantMethod(f, a, b, tol);
    end = clock();
    double secantTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Bisection Method: Root = " << rootBisection << ", Time = " << bisectionTime << " seconds\n";
    cout << "Newton-Raphson Method: Root = " << rootNewton << ", Time = " << newtonTime << " seconds\n";
    cout << "Secant Method: Root = " << rootSecant << ", Time = " << secantTime << " seconds\n";

    return 0;
}

