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

double derivativeApproximation(double x, double h, functionCall f)
{
	return ((f(x + h) - f(x)) / h);
}

double secantMethod(double x0, functioncall f, double tol, int maxiter)
{
	int iter = 0;
	double error = 10.0 * tol;
	double x1;

	while(error > tol && iter < maxiter)
	{
		iter++;
		x1 = x0 - (f(x0) / derivativeApproximation(x0, 0.001, f));
		error = abs(x1 - x0); // Not using relative error because we don't want to accidentally divide by 0
		// cout << "x0 = " << x0 << " : x1 = " << x1 << endl;
		x0 = x1;
	}
	return x1;
}

int main()
{
	cout.precision(10);
	cout << "Secant Method root of f(x) = x^2 - 3 with x0 = 10 : " << secantMethod(10, f1, 0.001, 100) << endl;
	cout << "Secant Method root of f(x) = sin(pi * x) with x0 = 3.33 : " << secantMethod(3.33, f2, 0.001, 100) << endl;

	return 0;
}
