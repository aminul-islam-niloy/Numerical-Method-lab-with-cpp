#include<bits/stdc++.h>
using namespace std;
//polinomial_curve_fitting
class polinomial_curve_fitting
{
    private: int i,j,k,n;
    
    private: double x[100],y[100],a[100];    
    private: double X[100],Y[100],B[100][100];

    
    public: polinomial_curve_fitting()
    {
        
    }


    public: void polinomial_fitting(double x[100], double y[100], double N)
    {
        cout << "\nWhat degree of Polynomial do you want to use for the fit?\n";
        cin >> n;            // n is the degree of Polynomial
        X[2 * n + 1]; // Array that will store the values of sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
        for (i = 0; i < 2 * n + 1; i++)
        {
            X[i] = 0;
            for (j = 0; j < N; j++)
                X[i] = X[i] + pow(x[j], i); // consecutive positions of the array will store N,sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
        }
        B[n + 1][n + 2], a[n + 1]; // B is the Normal matrix(augmented) that will store the equations, 'a' is for value of the final coefficients
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                B[i][j] = X[i + j]; // Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix
        Y[n + 1];            // Array to store the values of sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
        for (i = 0; i < n + 1; i++)
        {
            Y[i] = 0;
            for (j = 0; j < N; j++)
                Y[i] = Y[i] + pow(x[j], i) * y[j]; // consecutive positions will store sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
        }
        for (i = 0; i <= n; i++)
            B[i][n + 1] = Y[i]; // load the values of Y as the last column of B(Normal Matrix but augmented)
        n = n + 1;              // n is made n+1 because the Gaussian Elimination part below was for n equations, but here n is the degree of polynomial and for n degree we get n+1 equations
        cout << "\nThe Normal(Augmented Matrix) is as follows:\n";
        for (i = 0; i < n; i++) // print the Normal-augmented matrix
        {
            for (j = 0; j <= n; j++)
                cout << B[i][j] << setw(16);
            cout << "\n";
        }
        gaussElimination(B, n, a); // Perform Gaussian Elimination
    }



    public: void gaussElimination(double B[100][100],int n, double a[100])
    {
        for (i = 0; i < n; i++) // From now Gaussian Elimination starts(can be ignored) to solve the set of linear equations (Pivotisation)
            for (k = i + 1; k < n; k++)
                if (B[i][i] < B[k][i])
                    for (j = 0; j <= n; j++)
                    {
                        double temp = B[i][j];
                        B[i][j] = B[k][j];
                        B[k][j] = temp;
                    }

        for (i = 0; i < n - 1; i++) // loop to perform the gauss elimination
            for (k = i + 1; k < n; k++)
            {
                double t = B[k][i] / B[i][i];
                for (j = 0; j <= n; j++)
                    B[k][j] = B[k][j] - t * B[i][j]; // make the elements below the pivot elements equal to zero or elimnate the variables
            }
        for (i = n - 1; i >= 0; i--) // back-substitution
        {                            // x is an array whose values correspond to the values of x,y,z..
            a[i] = B[i][n];          // make the variable to be calculated equal to the rhs of the last equation
            for (j = 0; j < n; j++)
                if (j != i) // then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                    a[i] = a[i] - B[i][j] * a[j];
            a[i] = a[i] / B[i][i]; // now finally divide the rhs by the coefficient of the variable to be calculated
        }
        print_ans(a, n); // print the values of x,y,z..
    }


    public: void print_ans(double a[100],int n)
    {
        cout << "\nThe values of the coefficients are as follows:\n";
        for (i = 0; i < n; i++)
            cout << "x^" << i << "=" << a[i] << endl; // Print the values of x^0,x^1,x^2,x^3,....
        cout << "\nHence the fitted Polynomial is given by:\ny=";
        for (i = 0; i < n; i++)
            cout << " + (" << a[i] << ")"
                 << "x^" << i;
        cout << "\n";
    }

};

int main()
{
    polinomial_curve_fitting pcf;
    double N;
    cout << "Enter the number of data points:" << endl;
    
    cin >> N;
    double x[100],y[100];
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];        
    }
    for (int i = 0; i < N; i++)
    {
        cin >> y[i];
    }
    pcf.polinomial_fitting(x,y,N);
    
    return 0;
}