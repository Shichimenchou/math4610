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
	
	vector<double> xy = vecAdd(x, y, 5);
	
	for(int i = 0; i < 5; i++)
	{
		cout << xy[i] << " ";
	}
	cout << endl;
	
	
	vector<double> xy2 = vecSub(x, y, 5);
	
	for(int i = 0; i < 5; i++)
	{
		cout << xy2[i] << " ";
	}
	cout << endl;
	
	double b = 5.0;
	vector<double> bx = vecScalMul(x, b, 5);
	
	for(int i = 0; i < 5; i++)
	{
		cout << bx[i] << " ";
	}
	cout << endl;
	
	vector<double> z;
	
	z.push_back(1);	
	z.push_back(2);
	z.push_back(3);
	z.push_back(4);
	z.push_back(5);	

	cout << dotProd(x, z, 5) << endl;

	vector<double> u;
	vector<double> w;
	u.push_back(1);
	u.push_back(1);
	u.push_back(1);
	w.push_back(1);
	w.push_back(2);
	w.push_back(3);
	
	vector<vector<double>> uw = outerProd(u, w, 3);
	
	for(size_t i = 0; i < 3; i++)
	{
		cout << uw[i][0] << " " << uw[i][1] << " " << uw[i][2] << endl;
	}
	

	return 0;
}
