#include <iostream>

using namespace std;

typedef double (* functionCall)(double x);

double f1(double x)
{
	return (x * x) - 3;
}

double g1(double x)
{
	return x - f1(x);
}

int main()
{
	// UNDONE!!
}
