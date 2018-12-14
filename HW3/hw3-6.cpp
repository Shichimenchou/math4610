#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<double>> transpose(vector<vector<double>> A, int n, int m)
{
	vector<vector<double>> At;

	for(int j = 0; j < m; j++)
	{
		vector<double> row;
		for(int i = 0; i < n; i++)
		{
			row.push_back(A[i][j]);
		}
		At.push_back(row);
	}

	return At;
}

vector<vector<double>> matAdd(vector<vector<double>> A, vector<vector<double>> B, int n, int m)
{
	vector<vector<double>> ans;

	for(int i = 0; i < n; i++)
	{
		vector<double> row;
		for(int j = 0; j < m; j++)
		{
			row.push_back(A[i][j] + B[i][j]);
		}
		ans.push_back(row);
	}

	return ans;
}

vector<vector<double>> matScalMul(vector<vector<double>> A, double b, int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			A[i][j] = A[i][j] * b;
		}
	}

	return A;
}

vector<vector<double>> matMul(vector<vector<double>> A, vector<vector<double>> B, int n, int m)
{
	vector<vector<double>> ans;

	for(int i = 0; i < n; i++)
	{
		vector<double> row;
		for(int j = 0; j < m; j++)
		{
			double val = 0.0;
			for(int k = 0; k < m; k++)
			{
				val += A[i][k] * B[k][j];
			}		
			row.push_back(val);
		}
		ans.push_back(row);
	}
	return ans;
}

vector<vector<double>> matOutProd(vector<vector<double>> A, vector<vector<double>> B, int n, int m)
{
	vector<vector<double>> Bt = transpose(B, m, n);

	return matMul(A, Bt, n, m);
}

// A is n x m, B is p x q, A x B is np x mq
vector<vector<double>> KroeProd(vector<vector<double>> A, vector<vector<double>> B, int n, int m, int p, int q)
{
	vector<vector<double>> ans;

	for(int i = 0; i < n; i++)
	{
		vector<double> row;
		for(int k = 0; k < p; k++)
		{
			for(int j = 0; j < m; j++)
			{
				for(int l = 0; l < q; l++)
				{
					row.push_back(A[i][j] * B[k][l]);	
				}
			}
			ans.push_back(row);
		}
	}

	return ans;	
}

double det2(vector<vector<double>> A)
{
	return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}

double detN(vector<vector<double>> A, int n)
{
	while(n > 2)
	{
		vector<vector<double>> smaller;
		for(int i = 0; i < n - 1; i++)
		{
			vector<double> row;
			for(int j = 0; j < n - 1; j++)
			{
				row.push_back(0.0);
			}
			smaller.push_back(row);
		}

		for(int i = 0; i < n; i++)
		{
			vector<vector<double>> temp;
			for(int j = 0; j < n - 1; j++)
			{
				vector<double> row;
				for(int k = 0; k < n - 1; k++)
				{
					if(j != i && k != i)
					{
						row.push_back(A[i][i] * A[j][k] * pow(-1, (i % 2) + 1));
					}
				}
				temp.push_back(row);
			}
			smaller = matAdd(smaller, temp, n-1, n-1);
		}
		n--;
		if(n == 2)
		{
			return det2(smaller);	
		}
		else
		{
			A = smaller;
		}
	}
	return -1000000;
}

int main()
{
	

	return 0;
}
