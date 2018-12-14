# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           dotProd

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the dot product of two vectors

**Input:** The inputs are two vector of doubles x and y, and the length of the vector int length

**Output:** This routine returns a double, the dot product of x and y

**Usage/Example:** The following lines of code compute in the main function the dot product of two vectors

    vector<double> x;
    vector<double> z;
    vector<double> z;
    x.push_back(1);
    x.push_back(1);
    x.push_back(1);
    x.push_back(1);
    z.push_back(1);	
    z.push_back(2);
    z.push_back(3);
    z.push_back(4);
    z.push_back(5);	

    cout << dotProd(x, z, 5) << endl;
	
The output follows

    15

**Implementation/Code:** The following is the code for dotProd and the main function to run the method

	#include <iostream>
	#include <vector>
	#using namespace std;

	double dotProd(vector<double> x, vector<double> y, int length)
	{
		double sum = 0.0;

		for(int i = 0; i < length; i++)
		{
			sum += x[i] * y[i];
		}

		return sum;
	}

	int main()
	{
		vector<double> x;
		vector<double> z;
		x.push_back(1);
		x.push_back(1);
		x.push_back(1);
		x.push_back(1);
		z.push_back(1);	
		z.push_back(2);
		z.push_back(3);
		z.push_back(4);
		z.push_back(5);	

		cout << dotProd(x, z, 5) << endl;

		return 0;
	}

**Last Modified: December 2018**
