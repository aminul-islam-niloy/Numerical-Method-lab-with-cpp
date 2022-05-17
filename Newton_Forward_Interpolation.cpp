#include<bits/stdc++.h>
using namespace std;


class Newton_Forward_Interpolation
{
    private: double x[10],y[10][10],sum,p,u,temp,value;
    private: int n,i,j,k,f,m;

    public: Newton_Forward_Interpolation()
    {
        k = 0;
        i = 0;        
    }

    public: void add_data(double a, double b)
    {       
        x[i] = a;
        y[i][k] = b;        
        i++;
    }

    public: void printData(int n)
    {
        cout << "\nX\tY\n";        
        for (int i = 0; i < n; i++)
        {
            cout << x[i] << "\t" << y[i][k] << endl;
        }
    }

    private: void makeDifferenceTable(int n)
    {
        
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < n - i; j++)
            {
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
            }
        }        
    }
    //Display forward difference table
    public: void getDifferenceTable(int n)
    {        
       /*  cout << "\n_____________________________________________________\n";
        cout << "\n  x(i)\t   y(i)\t    y1(i)    y2(i)    y3(i)    y4(i)";
        cout << "\n_____________________________________________________\n";

        for (i = 0; i < n; i++)
        {
            cout << "\n" << x[i];
            for (j = 0; j < n - i; j++)
            {
                cout << "   ";
                cout << " " << y[i][j];
            }

            cout << "\n";
        } */

        for (int i = 0; i < n; i++)
        {
            cout << setw(4) << x[i]<< "\t";
            for (int j = 0; j < n - i; j++)
                cout << setw(4) << y[i][j]<< "\t";
            cout << endl;
        }
    }

    public: double u_cal(double u,int n)
    {
        temp = u;
        for (int i = 1; i < n; i++)
            temp = temp * (u - i);
        return temp;
    }

    public: int factorial(int n)
    {
        
            int f = 1;
            for (int i = 2; i <= n; i++)
                f *= i;
            return f;        
    }

    public: double fun(double value, int n)
    {
        //printData(n);
        makeDifferenceTable(n);
       
        
        sum = y[0][0];        
        u = (value - x[0]) / (x[1] - x[0]);      
        for (int i = 1; i < n; i++)
        {
            sum = sum + (u_cal(u, i) * y[0][i]) / factorial(i);            
        }

        return sum;
    }
};

int main()
{
    Newton_Forward_Interpolation obj;
    double x,y;
    int n,it;
    cout << "How many record you will be enter: "<<endl;
    cin >> n;
    it = n;    
    printf("Enter the tabulated points in the format x y:\n");
    while(it--)
    {
        cin >> x >> y;
        obj.add_data(x,y);
    }
    double point;
    printf("Enter the value of x for which you want to find the y:\n");
    scanf("%lf",&point);    
    
    printf("\nvalue at %lf is %0.10lf\n",point,obj.fun(point,n));
    cout<<endl<<endl;
    obj.getDifferenceTable(n);
    return 0;
}