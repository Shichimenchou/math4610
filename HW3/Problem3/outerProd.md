# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           outerProd

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the outer product of two vectors

**Input:** The inputs are two vector of doubles x and y, and the length of the vector int length

**Output:** This routine returns a double, the outer product of x and y

**Usage/Example:** The following lines of code compute in the main function the outer product of two vectors

    vector<double> x;
    vector<double> y;
    x.push_back(1);
    x.push_back(1);
    x.push_back(1);
    x.push_back(1);
    y.push_back(1);	
    y.push_back(2);
    y.push_back(3);
    y.push_back(4);
    y.push_back(5);	

    cout << outerProd(x, y, 5) << endl;
	
The output follows

    15

**Implementation/Code:** The following is the code for outerProd and the main function to run the method

	#include <iostream>
	#include <vector>
  
	#using namespace std;


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
		y.push_back(1);	
		y.push_back(2);
		y.push_back(3);
		y.push_back(4);
		y.push_back(5);	

		

		return 0;
	}

**Last Modified: December 2018**
