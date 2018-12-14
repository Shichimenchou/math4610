# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           froNormMat

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate frobenius matrix norm

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
	
  cout << "The Frobenius Norm of A is: " << frobNormMat(A, 5, 3) << endl;
	
The output follows

  17.3205

**Implementation/Code:** The following is the code for dotProd and the main function to run the method

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double frobNormMat(vector<vector<double>> A, int n, int m)
{
	double sum = 0.0;
	double rowSum = 0.0;

	for(int i = 0; i < n; i++)
	{
		rowSum = 0.0;
		for(int j = 0; j < m; j++)
		{
			rowSum += A[i][j] * A[i][j];
		}

		sum += sqrt(rowSum);
	}

	return sum;
}

double infNormMat(vector<vector<double>> A, int n, int m)
{
	double ans = 0.0;
	double rowSum = 0.0;

	for(int i = 0; i < n; i++)
	{
		rowSum = 0.0;
		for(int j = 0; j < m; j++)
		{
			rowSum += A[i][j];
		}

		if(rowSum > ans)
		{
			ans = rowSum;
		}
	}

	return ans;
}

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
	
	cout << "The Frobenius Norm of A is: " << frobNormMat(A, 5, 3) << endl;

	return 0;
}

**Last Modified: December 2018**
