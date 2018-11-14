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

double bisection(double a, double b, functionCall f, double tol, int maxiter) 
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
	while(error > tol && iter < maxiter)
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
	return c;
}

int main()
{
	cout << bisection(1, 5, f1, .001, 100) << endl;
	cout << bisection(-1, 10, f2, .001, 100) << endl;

	return 0;
}
