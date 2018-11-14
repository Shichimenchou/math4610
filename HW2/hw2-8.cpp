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
		x0 = x1;
	}
	return x1;
}

double hybridNewton(double a, double b, functionCall f, functionCall fp, double tol, int maxiter) 
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
	
	
	return newtonsMethod(abs(a - b) / 2, f, fp, tol, maxiter - iter);
}

int main()
{
	cout.precision(10);
	cout << "Newton's Method Hybrid root of f(x) = x^2 - 3 with x0 = 10 : " << hybridNewton(10, f1, f3, 0.001, 100) << endl;
	cout << "Newton's Method Hybrid root of f(x) = sin(pi * x) with x0 = 3.33 : " << hybridNewton(3.33, f2, f4, 0.001, 100) << endl;
	
	return 0;
}
