# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           absErr1

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will implement the absErr1 method

**Input:** The inputs are vectors of doubles, an actual vector x and an approximation y, and the length of the two vectors, int length

**Output:** This routine returns a double value: absolute error between them using the oneNorm

**Usage/Example:** 

**Implementation/Code:** The following is the code for absErr1 and the main function to run the method

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

	double absErr1(vector<double> x, vector<double> y, int length)
	{
		vector<double> e;

		for(int i = 0; i < length; i++)
		{
			e.push_back(x[i] - y[i]);
		}

		return oneNorm(e, length);
	}

	double absErr2(vector<double> x, vector<double> y, int length)
	{
		vector<double> e;

		for(int i = 0; i < length; i++)
		{
			e.push_back(x[i] - y[i]);
		}

		return twoNorm(e, length);
	}

	double absErrInf(vector<double> x, vector<double> y, int length)
	{
		vector<double> e;

		for(int i = 0; i < length; i++)
		{
			e.push_back(x[i] - y[i]);
		}

		return infNorm(e, length);
	}

	double relErr1(vector<double> x, vector<double> y, int length)
	{
		vector<double> e;

		for(int i = 0; i < length; i++)
		{
			e.push_back(x[i] - y[i]);
		}

		return (oneNorm(e, length) / oneNorm(x, length));
	}

	double relErr2(vector<double> x, vector<double> y, int length)
	{
		vector<double> e;

		for(int i = 0; i < length; i++)
		{
			e.push_back(x[i] - y[i]);
		}

		return (twoNorm(e, length) / twoNorm(x, length));
	}

	double relErrInf(vector<double> x, vector<double> y, int length)
	{
		vector<double> e;

		for(int i = 0; i < length; i++)
		{
			e.push_back(x[i] - y[i]);
		}

		return (infNorm(e, length) / infNorm(x, length));
	}

	int main()
	{
		vector<double> x;
		x.push_back(1.0);
		x.push_back(1.0);
		x.push_back(1.0);

		vector<double> y;
		y.push_back(0.0);
		y.push_back(0.0);
		y.push_back(0.0);

		cout << absErr1(x, y, 3) << endl;
		cout << absErr2(x, y, 3) << endl;
		cout << absErrInf(x, y, 3) << endl;
		cout << relErr1(x, y, 3) << endl;
		cout << relErr2(x, y, 3) << endl;
		cout << relErrInf(x, y, 3) << endl;

		return 0;
	}

**Last Modified: December 2018**
