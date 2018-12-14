# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           outerProd

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the outer product of two vectors

**Input:** The inputs are two vector of doubles x and y, and the length of the vector int length

**Output:** This routine returns a double, the outer product of x and y

**Usage/Example:** The following lines of code compute in the main function the outer product of two vectors

	vector<vector<double>> uw = outerProd(u, w, 3);
	
	for(size_t i = 0; i < 3; i++)
	{
		cout << uw[i][0] << " " << uw[i][1] << " " << uw[i][2] << endl;
	}
	
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
		vector<vector<double>> uw = outerProd(u, w, 3);
	
		for(size_t i = 0; i < 3; i++)
		{
			cout << uw[i][0] << " " << uw[i][1] << " " << uw[i][2] << endl;
		}
		return 0;
	}

**Last Modified: December 2018**
