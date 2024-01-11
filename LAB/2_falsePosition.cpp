#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double c;

double func(double x) {
    return pow(x, 3) - 3 * x - 5;
}

void falsePosition(double a, double b, double error, int maxIterations) {
    if (func(a) * func(b) > 0) {
        cout << "Error: The root is not bracketed correctly.\n";
        return;
    }

    int iteration = 1;
    c = a;

    cout << setw(5) << "Iter" << setw(15) << "a" << setw(15) << "b" << setw(15) << "c" << setw(15) << "f(c)" << endl;

    while (iteration <= maxIterations) {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        cout << setw(5) << iteration
             << setw(15) << a
             << setw(15) << b
             << setw(15) << c
             << setw(15) << func(c)
             << endl;

        if (fabs(func(c)) < error) {
            cout << "\nRoot found at x = " << c << "\t f(x) = " << func(c) << endl;
            break;
        } else if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    cout << "\nThe root is approximately: " << setprecision(8) << c << endl;
}

int main() {
    double a, b, err;
    int maxIterations;

    cout << "Enter lower bound: ";
    cin >> a;
    cout << "Enter upper bound: ";
    cin >> b;
    cout << "Enter tolerable error: ";
    cin >> err;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIterations;
    cout << endl;

    falsePosition(a, b, err, maxIterations);

    return 0;
}
