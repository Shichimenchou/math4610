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
	vector<vector<double>> A;
	
	for(int i = 0; i < 3; i++)
	{
		vector<double> row;
		for(int j = 0; j < 3; j++)
		{
			row.push_back(i + 1);
		}
		A.push_back(row);
	}
	
	vector<vector<double>> AplusB = matAdd(A, A, 3, 3);
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << AplusB[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	vector<vector<double>> AminusB = matSub(A, A, 3, 3);
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << AminusB[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << trace(A, 3) << endl;
	
	vector<vector<double>> bA = matScalMul(A, 2, 3, 3);
	cout << endl;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << bA[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	vector<double> x;
	x.push_back(1);
	x.push_back(1);
	x.push_back(1);
	
	vector<double> Ax = matVecMul(A, x, 3, 3);
	
	for(int i = 0; i < 3; i++)
	{
		cout << Ax[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	vector<vector<double>> AA = matMul(A, A, 3, 3);
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << AA[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
