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

// This function returns the sin(x) using the taylor series approximation up to 10 terms
double f1(double x)
{
	double ans = 0.0;
	double mult = x;

	
	for(int i = 3; i < 20; i += 2)
	{
		ans += mult;
		mult *= - x * x / (i * (i - 1));
	}
	ans += mult;

	return ans;
}

int main(int argc, char **argv)
{
	double h = 1.0;
	for(int i = 0; i < 50; i++)
	{
		cout << "The derivative approximation of d/dx sin(x) with x = 0 and h = " << h << " is ";
		cout << derivativeApproximation(0.0, h, f1) << endl;
		cout << "The conjugate approximation of d/dx sin(x) with x = 0 and h = " << h << " is ";
		cout << conjugateApproximation(0.0, h, f1) << endl;
		h /= 2;
	}
	
	return 0;
}

