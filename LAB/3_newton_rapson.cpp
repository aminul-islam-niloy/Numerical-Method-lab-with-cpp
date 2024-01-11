#include <iostream>
#include <cmath>
using namespace std;

double function(double x)
{
    // Define your non-linear equation here
    return x * x - 4; // Example: x^2 - 4 = 0
}

double derivative(double x)
{
    // Define the derivative of your function here
    return 2 * x; // Example: derivative of x^2 - 4 is 2*x
}

double newton_method(double x0, double tol, int max_iter)
{
    double x = x0;

    for (int iter = 1; iter <= max_iter; ++iter)
    {
        double fx = function(x);
        double dfx = derivative(x);

        x = x - fx / dfx;

        if (abs(fx) < tol)
        {
            cout << "Root found at iteration " << iter << ": " << x << endl;
            return x;
        }
    }

    cout << "Maximum iterations reached. No root found within the specified tolerance." << std::endl;
    return x; // You might want to handle this case differently
}

int main()
{
    double x0 = 3.0;     // Initial guess
    double tol = 0.0001; // Tolerance
    int max_iter = 100;  // Maximum number of iterations

    newton_method(x0, tol, max_iter);

    return 0;
}
