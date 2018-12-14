#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double oneNorm(vector<double> v, int length)
{
	double sum = 0.0;

	for (int i = 0; i < length; i++)
	{
		sum += v[i];
	}

	return sum;
}

double twoNorm(vector<double> v, int length)
{
	double sum = 0.0;

	for (int i = 0; i < length; i++)
	{
		sum += v[i] * v[i];
	}

	return sqrt(sum);
}

double infNorm(vector<double> v, int length)
{
	double max = 0.0;

	for (int i = 0; i < length; i++)
	{
		if (abs(v[i]) > max)
		{
			max = abs(v[i]);
		}
	}

	return max;
}

int main()
{
	vector<double> v = { 1, 1, 1, 1, 1 };

	cout << oneNorm(v, 5) << endl;
	cout << twoNorm(v, 5) << endl;
	cout << infNorm(v, 5) << endl;

	return 0;
}
