#include<iostream>
using namespace std;

double c;

double func(double x) {
    return x * x * x - x * x + 2;
}

void bisection(double a, double b, double error) {
    if (func(a) * func(b) > 0) {
        cout << "Error: The root is not bracketed correctly.\n";
        return;
    }

    c = a;

    while ((b - a) >= error) {
        c = (a + b) / 2;

        if (func(c) == 0.0) {
            cout << "Root found at x = " << c << "\t f(x) = " << func(c) << endl;
            break;
        } else if ((func(c) * func(a)) < 0) {
            cout << "Root found at x = " << c << "\t f(x) = " << func(c) << endl;
            b = c;
        } else {
            cout << "Root found at x = " << c << "\t f(x) = " << func(c) << endl;
            a = c;
        }
    }

    cout << "\nThe root is: " << c << endl;
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
