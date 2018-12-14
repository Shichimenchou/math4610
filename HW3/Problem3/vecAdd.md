# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           vecAdd

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will implement add two vectors

**Input:** The inputs are vectors of doubles, x and y

**Output:** This routine returns a vector of doubles, x + y

**Usage/Example:** The following lines of code compute in the main function output the values of the entries in the new vector

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
	
The output follows

	2
  	2
  	2
  	2
  	2

**Implementation/Code:** The following is the code for vecAdd and the main function to run the method

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

	    return 0;
	  }

**Last Modified: December 2018**
