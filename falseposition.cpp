#define f(x) x*x*x - x*x + 2
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{

	 float x0, x1, x, f0, f1, f, e;
	 int count = 1;


     cout<< setprecision(6)<< fixed;


	 up:
	 cout<<"Enter first guess: ";
     cin>>x0;
     cout<<"Enter second guess: ";
     cin>>x1;
     cout<<"Enter tolerable error: ";
     cin>>e;


	 f0 = f(x0);
	 f1 = f(x1);


	 if( f0 * f1 > 0.0)
	 {
		  cout<<"Incorrect Initial Guesses."<< endl;
		  goto up;
	 }

	 do
	 {
		  x= (x0*f1- x1*f0)/(f1-f0);
		  f = f(x);

		  cout<<"Iteration "<< count<<":\t x = "<< setw(10)<< x<<" & f(x) = "<< setw(10)<< f(x)<< endl;

		  if( f0 * f < 0)
		  {
			   x1 = x;
			   f1 = f;
		  }
		  else
		  {
			   x0 = x;
			   f0 = f;
		  }
		  count = count + 1;
	 }while(fabs(f)>e);

	 cout<< endl<<"Root is: "<< x<< endl;

	 return 0;
}

