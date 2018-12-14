# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           matScalMul.md

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the product of a matrix and a scalar

**Input:** The inputs a vector of vector of doubles, A, and the dimensions of the matrix, n and m, and the scalar

**Output:** This routine returns a matrix, the product of the matrix and the scalar

**Usage/Example:** The following lines of code compute the produt of a matrix and a scalar, and the main function tests the method
	
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

    vector<vector<double>> bA = matScalMul(A, 2, 3, 3);

    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        cout << bA[i][j] << " ";
      }
      cout << endl;
    }
	
The output follows

    2 2 2
    4 4 4
    6 6 6

**Implementation/Code:** The following is the code for matScalMul and the main function to run the method

	  #include <iostream>
	  #include <vector>

	  using namespace std;

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

	    vector<vector<double>> bA = matScalMul(A, 2, 3, 3);

	    for(int i = 0; i < 3; i++)
	    {
	      for(int j = 0; j < 3; j++)
	      {
		cout << bA[i][j] << " ";
	      }
	      cout << endl;
	    }

	    return 0;
	  }

**Last Modified: December 2018**
