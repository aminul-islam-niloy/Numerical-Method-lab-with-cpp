#include<bits/stdc++.h>
using namespace std;

class Secant
{
    private: double eps;
    private: double a, b, root;

    public: Secant()
    {
        a = 7, b = 8, root = -1;
    }

    public: double f(double x)
    {
        return x * x * x - 2 * x - 5;
    }

    public: double getRoot()
    {
        return root;
    }

    public: void findRoot(double eps)
    {
        do{
            root = b - (f(b) * (b-a))/(f(b) - f(a));
            a = b;
            b = root;

        }while(abs(f(root))>eps);
    }
};

int main()
{
    Secant secant;
    secant.findRoot(0.00001);
    printf("The root of the given equation : %0.10lf\n", secant.getRoot()); 
}