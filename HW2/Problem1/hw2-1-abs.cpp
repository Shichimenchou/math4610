#include <iostream>
#include <cmath>

using namespace std;

double absoluteError(double actual, double approximation)
{
	return abs(actual - approximation);
}

int main()
{
	double actual;
	cout << "Enter the actual value: ";
	cin >> actual;

	double approximation;
	cout << "Enter the approximation: ";
	cin >> approximation;

	cout << "The absolute error is: " << absoluteError(actual, approximation) << endl;

	return 0;
}
