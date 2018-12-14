#include <iostream>
#include <vector>

using namespace std;

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

vector<vector<double>> matSub(vector<vector<double>> A, vector<vector<double>> B, int n, int m)
{
	vector<vector<double>> ans;

	for(int i = 0; i < n; i++)
	{
		vector<double> row;
		for(int j = 0; j < m; j++)
		{
			row.push_back(A[i][j] - B[i][j]);
		}
		ans.push_back(row);
	}

	return ans;

}

double trace(vector<vector<double>> A, int n)
{
	double ans = 0.0;

	for(int i = 0; i < n; i++)
	{
		ans += A[i][i];
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

vector<double> matVecMul(vector<vector<double>> A, vector<double> x, int n, int m)
{
	vector<double> ans;
	double val = 0.0;

	for(int i = 0; i < n; i++)
	{
		val = 0.0;
		for(int j = 0; j < m; j++)
		{
			val += x[j] * A[i][j];
		}
		ans.push_back(val);
	}
	return ans;
}


// A is n x m, B is m x n, so the ans is n x n
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

int main()
{
	


	return 0;
}
