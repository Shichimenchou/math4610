# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           hw2-1-rel

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

For example,

    g++ hw2-1-rel.cpp

will produce an **./a.out** file.

**Description/Purpose:** This routine will compute the single relative error between two numbers.

**Input:** The inputs, in order, are two doubles, the actual value and the approximation.

**Output:** This routine returns a double value: the relative error between the actual and the approximation.

**Usage/Example:**

This main code asks for an actual value and an approximation, then returns the relative error. For instance, type 10.0 and 8.8 when prompted

	Enter the actual value: 10.0
	Enter the approximation: 8.8
    
This will yield the following output

	The absolute error is: 0.12

**Implementation/Code:** The following is the code for smaceps()
	
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

**Last Modified:** December/2018
