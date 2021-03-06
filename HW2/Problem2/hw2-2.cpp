#include <iostream>
#include <cmath>

using namespace std;

typedef double (* functionCall)(double x);

double integralApproximation(double x, double h, functionCall f)
{
	return ((f(x + h) - f(x)) / h);
}

double f1(double x)
{
	return x * x;
}

double f2(double x)
{
	return sin(x);
}

int main()
{
	double h = 1.0;
	for(int i = 0; i < 100; i++)
	{
		cout << "h = " << h << endl << "----------------------------" << endl;
		cout << "d/dx x^2 dx, x = 10 : " << integralApproximation(10, h, f1) << endl;
		cout << "d/dx sin(x) dx, x = 10 : " << integralApproximation(10, h, f2) << endl << endl;
		h /= 2;
	}
	
	return 0;
}

