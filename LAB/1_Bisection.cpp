#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double c;

double func(double x) {
    return 3 * x - cos(x) - 1;
}

void bisection(double a, double b, double error) {
    if (func(a) * func(b) > 0) {
        cout << "Error: The root is not bracketed correctly.\n";
        return;
    }

    int iteration = 1;
    c = a;

    cout << setw(5) << "Iter" << setw(15) << "a" << setw(15) << "b" << setw(15) << "c" << setw(15) << "f(c)" << endl;

    while ((b - a) >= error) {
        c = (a + b) / 2;

        cout << setw(5) << iteration
             << setw(15) << a
             << setw(15) << b
             << setw(15) << c
             << setw(15) << func(c)
             << endl;

        if (func(c) == 0.0) {
            cout << "\nRoot found at x = " << c << "\t f(x) = " << func(c) << endl;
            break;
        } else if ((func(c) * func(a)) < 0) {
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

    cout << "Enter first guess: ";
    cin >> a;
    cout << "Enter second guess: ";
    cin >> b;
    cout << "Enter tolerable error: ";
    cin >> err;
    cout << endl;

    bisection(a, b, err);

    return 0;
}
