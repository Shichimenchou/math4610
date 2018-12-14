# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           oneNormMat

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate matrix 1-norm

**Input:** The inputs are a vector of vector of doubles, and the dimensions of the matrix n and m

**Output:** This routine returns a double, the matrix norm

**Usage/Example:** The following lines of code from the main function return the matrix norm

	vector<vector<double>> A;
	
	for(int i = 0; i < 5; i++)
	{
		vector<double> row;
		for(int j = 0; j < 4; j++)
		{
			row.push_back(i);
		}
		A.push_back(row);
	}
	
  	cout << "The One Norm of A is: " << oneNormMat(A, 5, 3) << endl;
	
The output follows

  	10

**Implementation/Code:** The following is the code for oneNormMat and the main function to run the method

	#include <iostream>
	#include <vector>
	#include <math.h>

	using namespace std;

	

	double oneNormMat(vector<vector<double>> A, int n, int m)
	{
		double ans = 0.0;
		double colSum = 0.0;

		for(int i = 0; i < m; i++)
		{
			colSum = 0.0;
			for(int j = 0; j < n; j++)
			{
				colSum += A[j][i];
			}

			if(colSum > ans)
			{
				ans = colSum;
			}
		}

		return ans;
	}

	int main()
	{
		vector<vector<double>> A;

		for(int i = 0; i < 5; i++)
		{
			vector<double> row;
			for(int j = 0; j < 4; j++)
			{
				row.push_back(i);
			}
			A.push_back(row);
		}

		cout << "The One Norm of A is: " << oneNormMat(A, 5, 3) << endl;

		return 0;
	}

**Last Modified: December 2018**
