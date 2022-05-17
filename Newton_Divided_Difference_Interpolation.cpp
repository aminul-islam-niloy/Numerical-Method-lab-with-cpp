#include <bits/stdc++.h>
using namespace std;

class NewtonDividedDifference
{
private:
    double x[10], y[10][10], result, term, pro,sum;

private:
    int n, i, j, k, f, m;

public:
    NewtonDividedDifference()
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
    // Function to find the product term
    double proterm(int i, float value)
    {
        pro = 1;
        for (int j = 0; j < i; j++)
        {
            pro = pro * (value - x[j]);
        }
        return pro;
    }

    // Function for calculating
    // divided difference table
public:
        void dividedDiffTable(int n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[j + i]);
            }
        }
    }
    // Function for applying Newton's
    // divided difference formula
public:    
    float applyFormula(double value, int n)
    {
        sum = y[0][0];

        for (int i = 1; i < n; i++)
        {
            sum = sum + (proterm(i, value) * y[0][i]);
        }
        return sum;
    }
    
    // Function for displaying
    // divided difference table
public:
    void printDiffTable(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                cout << setprecision(4) << y[i][j] << "\t ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    NewtonDividedDifference obj;
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

    // calculating divided difference table
    obj.dividedDiffTable(n);

    // displaying divided difference table
    obj.printDiffTable(n);

    double point;
    printf("Enter the value of x for which you want to find the y:\n");
    scanf("%lf", &point);

    printf("\nvalue at %lf is %0.10lf\n", point, obj.applyFormula(point, n));
    cout << endl<< endl;
    return 0;
}