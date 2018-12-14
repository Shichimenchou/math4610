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

	for(int i = 0; i < n; i++)
	{
		colSum = 0.0;
		for(int j = 0; j < m; j++)
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
	


	return 0;
}
