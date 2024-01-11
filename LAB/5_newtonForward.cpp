#include <iostream>

double newton_interpolation(double x[], double y[], int n, double target)
{
    double result = 0.0;

    for (int i = 0; i < n; ++i)
    {
        double term = y[i];

        for (int j = 0; j < i; ++j)
        {
            term *= (target - x[j]) / (x[i] - x[j]);
        }

        result += term;
    }

    return result;
}

int main()
{
    // Example data points
    double x[] = {0.0, 1.0, 2.0, 3.0};
    double y[] = {1.0, 2.0, 4.0, 8.0};

    int n = sizeof(x) / sizeof(x[0]);

    // Example: Interpolate at x = 1.5
    double target = 1.5;
    double interpolatedValue = newton_interpolation(x, y, n, target);

    std::cout << "Interpolated value at x = " << target << ": " << interpolatedValue << std::endl;

    return 0;
}
