#include <iostream>
#include <cmath>

using namespace std;

typedef double (* functionCall)(double x);

double derivativeApproximation(double x, double h, functionCall f)
{
	return ((f(x + h) - f(x)) / h);
}

double conjugateApproximation(double x, double h, functionCall f)
{
	return ((f(x + h) * f(x + h) - f(x) * f(x)) / (h * f(x + h) + h * f(x)));
}

double f1(double x)
{
	return sqrt(x);
}

int main(int argc, char **argv)
{
	double h = 1.0;
	for(int i = 0; i < 50; i++)
	{
		cout << "The approximation of d/dx sqrt(x) with x = 2 and h = " << h << " is ";
		cout << derivativeApproximation(2, h, f1) << endl;
		cout << "The conjugate approximation of d/dx sqrt(x) with x = 2 and h = " << h << " is ";
		cout << conjugateApproximation(2, h, f1) << endl << endl;
		h /= 2;
	}
	
	return 0;
}


