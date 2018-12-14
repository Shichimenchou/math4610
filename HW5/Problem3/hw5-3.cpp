#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<double> JacobiIter(vector<vector<double>> A, vector<double> b, vector<double> x0, int maxiter, double tol, int n)
{
	int count = 0;
	double error = 1000000.0;
	
	while(count < maxiter && error > tol)
	{
		vector<double> x;
		count++;
		
		for(int i = 0; i < n; i++)
		{
			double sum = 0.0;
			for(int j = 0; j < n; j++)
			{
				if(j != i)
				{
					sum += A[i][j] * x0[j];
				}
			}
			x.push_back((b[i] - sum) / A[i][i]);
		}
		
		double errSum = 0.0;
		for(int i = 0; i < n; i++)
		{
			errSum += (x[i] - x0[i]) * (x[i] - x0[i]);
		}
		error = sqrt(errSum);
		x0 = x;
	}
	
	return x0;
}

int main()
{
	vector<vector<double>> A;
	vector<double> row1;
	vector<double> row2;
	row1.push_back(2);row1.push_back(1);
	row2.push_back(5);row2.push_back(7);
	A.push_back(row1);A.push_back(row2);
	
	vector<double> b;
	b.push_back(11);b.push_back(13);
	
	vector<double> x0;
	x0.push_back(1);x0.push_back(1);
	
	vector<double> x = JacobiIter(A, b, x0, 100, .1, 2);
	
	cout << x[0] << " " << x[1] << endl;
	
	return 0;
}

