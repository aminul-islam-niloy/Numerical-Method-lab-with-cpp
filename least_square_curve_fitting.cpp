#include<bits/stdc++.h>
using namespace std;
//least square curve fitting
class curve_fitting_least_square
{
    private: double ans[2];//ans[0] is the slope, ans[1] is the intercept    
    private: double sum_y, sum_x, sum_xy, sum_xx;//sum_y is the sum of y, sum_x is the sum of x, sum_xy is the sum of x*y, sum_xx is the sum of x*x

    public: curve_fitting_least_square()
    {
        sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;//initialize variables       
    }

    public: void least_square(double x[100], double y[100],double n)
    {
        for(int i=0; i<n; i++)
        {            
            sum_y += y[i];            
            sum_x += x[i];
            sum_xy += x[i]*y[i];
            sum_xx += x[i]*x[i];
        }
        double b = (n*sum_xy - sum_x*sum_y)/(n*sum_xx - sum_x*sum_x);//
        double a = (sum_xx*sum_y - sum_x*sum_xy)/(n*sum_xx - sum_x*sum_x);
        ans[0] = a;
        ans[1] = b;
        //return ans;
    }
    public: void get_ans()
    {
        cout << ("Regression line:") << endl;
        cout << ("Y = ");
        printf("%.3lf + ", ans[0]);
        printf("%.3lf *X", ans[1]);
    }    
};

int main()
{
    curve_fitting_least_square cfls;
    double n,x[100],y[100];
    //cout << "Enter the number of data points:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];        
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    cfls.least_square(x,y,n);
    cfls.get_ans();
    
    return 0;
}

/* Test Case: 
5
x: 95 85 80 70 60
y: 90 80 70 65 60
 */