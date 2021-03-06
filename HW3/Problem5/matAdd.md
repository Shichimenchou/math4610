# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           matAdd

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the sum of two matrices of the same size

**Input:** The inputs are two vectors of vectors of doubles, A and B, and the integer dimensions

**Output:** This routine returns a vector of vector of doubles, the matrix A + B

**Usage/Example:** The following lines of code compute in the main function the sum of two matrices

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
	
The output follows

    2 2 2
    4 4 4
    6 6 6

**Implementation/Code:** The following is the code for matAdd and the main function to run the method

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

	    return 0;
	  }

**Last Modified: December 2018**
