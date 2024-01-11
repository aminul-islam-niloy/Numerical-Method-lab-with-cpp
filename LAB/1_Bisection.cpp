#include <iostream>
#include <cmath>

double function(double x) {
    // Define your non-linear equation here
    return x*x - 4; // Example: x^2 - 4 = 0
}

double bisection(double a, double b, double tol, int max_iter) {
    double c;
    
    for (int iter = 1; iter <= max_iter; ++iter) {
        c = (a + b) / 2.0;
        
        if (std::abs(function(c)) < tol) {
            std::cout << "Root found at iteration " << iter << ": " << c << std::endl;
            return c;
        }

        if (function(c) * function(a) < 0)
            b = c;
        else
            a = c;
    }

    std::cout << "Maximum iterations reached. No root found within the specified tolerance." << std::endl;
    return c; // You might want to handle this case differently
}

int main() {
    double a = 0.0; // Initial left boundary
    double b = 3.0; // Initial right boundary
    double tol = 0.0001; // Tolerance
    int max_iter = 100; // Maximum number of iterations
    
    bisection(a, b, tol, max_iter);

    return 0;
}
