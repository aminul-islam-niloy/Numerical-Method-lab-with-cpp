#include <bits/stdc++.h>

using namespace std;

class Trapezoidal
{
private:
    double a, b, sum,h;
    int n;    

private:
    double function(double x)
    {

        return 1 / (1 + x * x);
    }

public:
    Trapezoidal(double b, double a, int n)
    {
        this->a = a;
        this->b = b;
        this->n = n;
    }    
public: 
    double solve()
    {  

        h = (b - a) / n;
        //cout<<"h="<<h<<endl;
        // Computing sum of first and last terms
        sum = function(a) + function(b);

        // Adding middle terms
        for (int i = 1; i < n; i++)
        {
            sum += 2 * function(a + i * h);
        }

        return (h / 2) * sum;
    }
};

int main()
{

    Trapezoidal *trapezoidal = new Trapezoidal(1, 0, 10);
    printf("Value of integral is %6.4f\n",trapezoidal->solve());
    return 0;
}