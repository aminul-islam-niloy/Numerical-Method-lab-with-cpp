#include <bits/stdc++.h>
using namespace std;

class Lagranges_interpolaton
{
private:
    double x[10], y[10][10], result, term;

private:
    int n, i, j, k, f, m;

public:
    Lagranges_interpolaton()
    {
        k = 0;
        i = 0;
        result = 0;
    }

public:
    void add_data(double a, double b)
    {
        x[i] = a;
        y[i][k] = b;
        i++;
    }

public:
    double interpolate(double interpolationPoint, int n)
    {
        for (int i = 0; i < n; i++)
        {
            // Compute individual terms of above formula
            double term = y[i][0];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    term = term * (interpolationPoint - x[j]) / (x[i] - x[j]);
            }

            // Add current term to result
            result += term;
        }
        return result;
    }
};

int main()
{
    Lagranges_interpolaton obj;
    double x, y;
    int n, it;
    cout << "How many record you will be enter: " << endl;
    cin >> n;
    it = n;
    printf("Enter the tabulated points in the format x y:\n");
    while (it--)
    {
        cin >> x >> y;
        obj.add_data(x, y);
    }
    double point;
    printf("Enter the value of x for which you want to find the y:\n");
    scanf("%lf", &point);

    printf("\nvalue at %lf is %0.10lf\n", point, obj.interpolate(point, n));
    cout << endl<< endl;    
    return 0;
}