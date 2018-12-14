# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           trace

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the trace of a matrix

**Input:** The inputs a vector of vector of doubles, A, and the dimension of the matrix int n

**Output:** This routine returns a double, the trace of the matrix

**Usage/Example:** The following lines of code compute the trace of a matrix, and the main function tests the method
	
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

    cout << trace(A, 3) << endl;
	
The output follows

    6

**Implementation/Code:** The following is the code for matSub and the main function to run the method

	  #include <iostream>
	  #include <vector>

	  using namespace std;

	  double trace(vector<vector<double>> A, int n)
	  {
	    double ans = 0.0;

	    for(int i = 0; i < n; i++)
	    {
	      ans += A[i][i];
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

	    cout << trace(A, 3) << endl;

	    return 0;
	  }

**Last Modified: December 2018**
