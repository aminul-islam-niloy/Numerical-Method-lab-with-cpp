#include<iostream>
using namespace std;

double c;
    double func(double x)
    {
        return x*x*x - x*x +2;
    }
void bisection(double a, double b,double error)
    {
        if(func(a)* func(b) >=0){
            cout<< "You have not assumed right a and b\n";
            return;
        }
      c=a;
    while ((b-a) >= error){
        c=(a+b)/2;
        if(func(c) == 0.0){
             printf("root = %lf\t function(c) = %lf\n", c, func(c));
            break;
        }

        else if( (func(c)* func(a)) <0){
          printf("root = %lf\t function(c) = %lf\n", c, func(c));
                b=c;
            }
        else{
             printf("root = %lf\t function(c) = %lf\n", c, func(c));
                a=c;
            }

    }
    cout<<endl;
    cout<< " The root is:"<<c<<endl;

    }

int main(){


     double a, b, err;

cout<<"Enter first guess: ";
     cin>>a;
     cout<<"Enter second guess: ";
     cin>>b;
     cout<<"Enter tolerable error: ";
     cin>>err;
     cout<<endl;
    bisection(a, b, err);

    return 0;

}
