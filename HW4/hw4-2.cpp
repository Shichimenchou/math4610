#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<double> GuassianElimination(vector<vector<double>> A, vector<double> x, int n, int m)
{
	double val = 0;
	for (int i = 0; i < min(n, m); i++)
	{
		val = A[i][i];
		if(val != 0)
		{
			if(val != 1)
			{
				for(int j = i; j < n; j++)
				{
					A[i][j] /= val;
				}
				x[i] /= val;
			}
			for(int j = 0; j < n; j++)
			{
				if(j != i)
				{
					val = A[j][i];
					for(int k = 0; k < n; k++)
					{
						A[j][k] -= A[i][k] * val;
					}
					x[j] -= x[i] * val;
				}
			}
		}
	}
	bool flag = false;
	bool cumulativeFlag = true;
	for(int i = 0; i < n; i++)
	{
		flag = false;
		if(x[i] != 0)
		{
			for(int j = 0; j < m; j++)
			{
				if(A[i][j] != 0)
				{
					flag = true;
					break;
				}
			}
			cumulativeFlag *= flag;
		}
		if(!cumulativeFlag)
		{
			break;
		}
	}
	if(!cumulativeFlag)
	{
		vector<double> error;
		for(int i = 0; i < m; i++)
		{
			error.push_back(-1000000.0);
		}
		return error;
	}
	return x;
}

int main()
{
	vector<vector<double>> A;
	vector<double> row1;
	row1.push_back(1);row1.push_back(3);row1.push_back(1);row1.push_back(1);
	vector<double> row2;
	row2.push_back(1);row2.push_back(1);row2.push_back(-1);row2.push_back(1);
	vector<double> row3;
	row3.push_back(3);row3.push_back(11);row3.push_back(5);row3.push_back(1);
	A.push_back(row1);A.push_back(row2);A.push_back(row3);


	vector<double> x;
	x.push_back(9);x.push_back(1);x.push_back(35);

	x = GuassianElimination(A, x, 3, 4);

	for(int i = 0; i < 3; i++)
	{
		cout << x[i] << " ";
	}

	return 0;
}
