#include <iostream>
#include<conio.h>
#include<math.h>

using namespace std;

float fdt[10][11],y=0,x,p=1,u;
int i,j,k,fac=1;

// FUNCTIONS DECLARATIONS
void input(void);           // FOR TAKING DATA FROM THE USER
void diff_table(void);      // FOR MAKING FORWARD DIFFERENCE TABLE
float x_cal(float,int);     // FOR CALCULATING THE VALUE OF U(U-1).....
int fact(int);              // FOR FINDING THE FACTORIAL
float calculate(float);     // FOR CALCULATING THE VALUE OF RESULTANT Y

int main()
{
    input();
    diff_table();
    y=calculate(x);
    cout<<"\n\nFOR x = "<<x<<", y = "<<y;
    return 0;
}
void input()
{
    cout<<"Enter the total number of set of points : ";
    cin>>k;

    for(i=1;i<=k;i++)
    {
        cout<<"\nX"<<i<<" = ";
        cin>>fdt[i][0];

        cout<<"Y"<<i<<" = ";
        cin>>fdt[i][1];
    }

    cout<<"\nEnter the value of x for which y is to be computed : ";
    cin>>x;
    return;
}

void diff_table()
{
    for(j=1;j<k;j++)
    {
        for(i=1;i<=k-j;i++)

        {
           if(j==1)
              fdt[i][j+1]=(fdt[i+1][j]-fdt[i][j])/(fdt[i+1][0]-fdt[i][0]);
           else
                fdt[i][j+1]=(fdt[i+1][j]-fdt[i][j])/(fdt[i+j][0]-fdt[i][0]);
        }
    }

    cout<<"\nDIVIDED DIFFERENCE TABLE \n\n";

    cout<<"x\ty\n\n";

    for(i=1;i<=k;i++)
    {
        cout<<fdt[i][0]<<"\t";
        for(j=1;j<=k-i+1;j++)
        {
            cout<<fdt[i][j]<<"\t";
        }
        cout<<"\n";
    }

}

int c;
float calculate(float x)
{
    for(i=1;i<=k;i++)
    {
        if(x<fdt[i+1][1])
        {
            break;
        }
    }

    for(j=1;j<=(k-i+1);j++)
    {
        c=i;
        y+=fdt[i][j]*x_cal(x,j-1);
    }
    return y;
}

float x_cal(float l,int m)
{
    p=1;
    if(m>0)
    {
        while(m>0)
        {
            p*= (l-fdt[c][0]);
            m-= 1;
            c++;
        }
    }
    return p;
}
