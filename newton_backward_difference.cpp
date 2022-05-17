#include <bits/stdc++.h>
using namespace std;

// calculating u mentioned in the formula
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

// calculating factorial of given number n
int fact(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}

int main()
{
	float x[20], y[20][20];
 int i,j, n;
 float value ;

 /* Input Section */
 cout << "Enter number of data? " << endl;
 cin >> n;

 cout << "Enter data: " << endl;
 for(i = 0; i < n ; i++)
 {
  cout << "x[" << i << "] = ";
  cin >> x[i];
  cout << "y[" << i <<"] = ";
  cin >> y[i][0];
 }

	// Calculating the Backward difference
	// table
	for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

	cout << "Enter the value of x: " << endl;
    cin >> value;

	cout<<"\nDIVIDED DIFFERENCE TABLE \n\n";
	// Displaying the forward difference table
	for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
    }

	// Value to interpolate at


	// initializing u and sum
	float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) /
                                     fact(i);
    }

	cout << "\n Value at " << value << " is "
		<< sum << endl;
	return 0;
}
