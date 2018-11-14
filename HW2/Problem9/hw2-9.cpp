#include <iostream>

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
		x0 = x1;
	}
	return x1;
}

double hybridSecant(double a, double b, functionCall f, double tol, int maxiter) 
{
	double fa = f(a);
	double fb = f(b);

	if(fa * fb > 0)
	{
		return -1000000.0;
	}
	if(fa * fb == 0)
	{
		if(fa == 0)
		{
			return fa;
		}
		if(fb == 0)
		{
			return fb;
		}
	}
	double error = 10 * tol;
	int iter = 0;
	double c, fc;
	while(error > 0.1 && iter < maxiter)
	{
		iter++;
		c = 0.5 * (a + b);
		fc = f(c);
		if(fc == 0)
			return c;
		if(fc * fa < 0)
		{
			b = c;
			fb = fc;
		}
		else
		{
			a = c;
			fa = fc;
		}
		error = abs(b - a);
	}
	
	
	return secantMethod(abs(a - b) / 2, f, tol, maxiter - iter);
}

int main()
{
	cout.precision(10);
	cout << "Secant Method Hybrid root of f(x) = x^2 - 3 with x0 = 10 : " << secantMethod(10, f1, 0.001, 100) << endl;
	cout << "Secant Method Hybrid root of f(x) = sin(pi * x) with x0 = 3.33 : " << secantMethod(3.33, f2, f4, 0.001, 100) << endl;
	
	return 0;
}

