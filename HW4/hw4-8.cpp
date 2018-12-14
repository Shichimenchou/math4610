#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<double>> CholeskyFactor(vector<vector<double>> M, int n)
{
	vector<vector<double>> L;
	double sum = 0.0;
	
	for(int i = 0; i < n; i++)
	{
		vector<double> row;
		for(int j = 0; j < n; j++)
		{
			row.push_back(0.0);
		}
		L.push_back(row);
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			sum = 0.0;
			if(i == j)
			{
				sum += M[i][j];
				for(int k = 0; k < j; k++)
				{
					sum -= L[j][k] * L[j][k];
				}
				L[i][j] = sqrt(sum);
			}
			else if(j < i)
			{
				sum += M[i][j];
				for(int k = 0; k < j; k++)
				{
					sum -= L[i][k] * L[j][k];
				}
				L[i][j] = sum / L[j][j];
			}
		}
	}
	
	return L;
}

int main()
{
	vector<vector<double>> A;
	vector<double> row1;vector<double> row2;vector<double> row3;
	row1.push_back(4);row1.push_back(12);row1.push_back(-16);
	row2.push_back(12);row2.push_back(37);row2.push_back(-43);
	row3.push_back(-16);row3.push_back(-43);row3.push_back(98);
	A.push_back(row1);A.push_back(row2);A.push_back(row3);

	vector<vector<double>> L = CholeskyFactor(A, 3);
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << L[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
