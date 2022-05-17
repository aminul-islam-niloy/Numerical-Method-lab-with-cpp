
#include<iostream>
using namespace std;

class NewtonRaphson
{
    private: double eps;
    private: double root;

    public: NewtonRaphson()
    {
        root = rand() % 10;

    }

    public: double equation(double x)
    {
        return x * x * x - 2 * x - 5;
    }

    public: double ddxf(double x)
    {
        return 3 * x * x - 2;
    }

    public : double getRoot()
    {
        return root;
    }

    public: void findRoot(double eps)
    {
        while(abs(equation(root))>eps)
            root = root - (equation(root)/ddxf(root));
    }
};

int main()
{
    NewtonRaphson newtonRaphson;
    newtonRaphson.findRoot(0.0001);
    printf("The root of the given equation : %0.10lf\n", newtonRaphson.getRoot());
}
