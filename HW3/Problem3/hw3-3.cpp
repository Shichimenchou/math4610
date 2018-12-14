#include <iostream>
#include <vector>

using namespace std;

vector<double> vecAdd(vector<double> x, vector<double> y, int length)
{
	vector<double> xy;
	
	for(int i = 0; i < length; i++)
	{
		xy.push_back(x[i] + y[i]);
	}
	
	return xy;
}

vector<double> vecSub(vector<double> x, vector<double> y, int length)
{
	vector<double> xy;
	
	for(int i = 0; i < length; i++)
	{
		xy.push_back(x[i] - y[i]);
	}
	
	return xy;
}

vector<double> vecScalMul(vector<double> x, double y, int length)
{
	vector<double> xy;
	
	for(int i = 0; i < length; i++)
	{
		xy.push_back( x[i] * y);
	}
	
	return xy;
}

double dotProd(vector<double> x, vector<double> y, int length)
{
	double sum = 0.0;

	for(int i = 0; i < length; i++)
	{
		sum += x[i] * y[i];
	}

	return sum;
}

vector<vector<double>> outerProd(vector<double> x, vector<double> y, int length)
{
	vector<vector<double>> ans;

	for(int i = 0; i < length; i++)
	{
		vector<double> row;
		for(int j = 0; j < length; j++)
		{
			row.push_back(x[i] * y[i]);
		}
		ans.push_back(row);
	}

	return ans;
}

int main()
{
	vector<double> x;
	vector<double> y;	
	x.push_back(1);
	x.push_back(1);
	x.push_back(1);
	x.push_back(1);
	x.push_back(1);	
	y.push_back(1);
	y.push_back(1);
	y.push_back(1);
	y.push_back(1);
	y.push_back(1);

	cout << dotProd(x, y, 5) << endl;
	cout << vecSub(x, y, 5)[0] << endl;

	return 0;
}
