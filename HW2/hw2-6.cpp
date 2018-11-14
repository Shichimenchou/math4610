#include <iostream>
#include <cmath>

using namespace std;

typedef double (* functionCall)(double x);

double f1(double x)
{
	return x * x - 3;
}

double f2(double x)
{
	return sin(3.1416 * x);
}

double f3(double x)
{
	return 2 * x;
}

double f4(double x)
{
	return 3.1416 * cos(3.1416 * x);
}

double newtonsMethod(double x0, functionCall f, functionCall fp, double tol, int maxiter) 
{
	int iter = 0;
	double error = 10.0 * tol;
	double x1;

	while(error > tol && iter < maxiter)
	{
		iter++;
		x1 = x0 - (f(x0) / fp(x0));
		error = abs(x1 - x0); // Not using relative error because we don't want to accidentally divide by 0
		// cout << "x0 = " << x0 << " : x1 = " << x1 << endl;
		x0 = x1;
	}
	return x1;
}

int main()
{	
	cout.precision(10);
	cout << "Newton's Method root of f(x) = x^2 - 3 with x0 = 10 : " << newtonsMethod(10, f1, f3, 0.001, 100) << endl;
	cout << "Newton's Method root of f(x) = sin(pi * x) with x0 = 3.33 : " << newtonsMethod(3.33, f2, f4, 0.001, 100) << endl;

	return 0;
}
