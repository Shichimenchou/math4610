#include <iostream>
#include <cmath>

using namespace std;

double relativeError(double actual, double relative)
{
	return abs(actual - relative) / actual;
}

int main()
{
	double actual;
	cout << "Enter the actual value: ";
	cin >> actual;

	double approximation;
	cout << "Enter the approximation: ";
	cin >> approximation;

	cout << "The relative error is: " << relativeError(actual, approximation) << endl;

	return 0;
}
