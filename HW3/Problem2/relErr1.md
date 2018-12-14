# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           relErr1

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will implement the relErr1 method

**Input:** The inputs are vectors of doubles, an actual vector x and an approximation y, and the length of the two vectors, int length

**Output:** This routine returns a double value: relative error between them using the oneNorm

**Usage/Example:** The following lines of code compute in the main function compute give the error for these two vector

	vector<double> x;
	x.push_back(1.0);
	x.push_back(1.0);		
	x.push_back(1.0);
	vector<double> y;
	y.push_back(0.2);
	y.push_back(0.2);
	y.push_back(0.2);

	cout << relErr1(x, y, 3) << endl;
	
The output follows

	0.8

**Implementation/Code:** The following is the code for relErr1 and the main function to run the method

	#include <iostream>
	#include <vector>
	#include <math.h>

	using namespace std;

	double relErr1(vector<double> x, vector<double> y, int length)
	{
		vector<double> e;

		for(int i = 0; i < length; i++)
		{
			e.push_back(x[i] - y[i]);
		}

		return (oneNorm(e, length) / oneNorm(x, length));
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
		
		cout << relErr1(x, y, 3) << endl

		return 0;
	}

**Last Modified: December 2018**
