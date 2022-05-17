#include <bits/stdc++.h>
using namespace std;

class FalsePosition
{
private:
    double eps;

private:
    double a, b, root, xa, xb, epsr, xrp, xr;

public:
    FalsePosition()
    {
        a = 0, b = 0, root = -1, xrp = 10, epsr = 10; // Initialize all variables
    }

public:
    double equation(double x)
    {
        return x * x * x - 2 * x - 5;
    }

public:
    void findInterval()
    {
        do
        {
            a = rand() % 10;
            b = rand() % 10;

            if (rand() % 2)
                a *= -1;
            if (rand() % 2)
                b *= -1;

        } while (equation(a) * equation(b) > 0);

        if (a > b)
            swap(a, b);
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot(double eps)
    {
        //cout<<"HI"<<endl;
        findInterval();
        cout << a << " " << b << endl;

        
        xa = a;
        xb = b;

        do
        {
            xr = xa - (xb - xa) * equation(xa) / (equation(xb) - equation(xa));

            if (equation(xr) == 0)
                break;

            if (equation(xr) > 0)
                xb = xr;
            else
                xa = xr;

            //cout << xa << " " << xb << endl;

            epsr = abs((xr - xrp) / xr);
            xrp = xr;

        } while (epsr > eps);
        root = xr;
    }
};

int main()
{
    FalsePosition falsePosition;
    falsePosition.findRoot(0.00001);
    printf("The root of the given equation : %0.10lf\n", falsePosition.getRoot());
}