# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           matVecMul

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the product of a matrix and a vector

**Input:** The inputs a vector of vector of doubles, A, a vector of doubles x, and the dimension of the vector n and m

**Output:** This routine returns a vector, the product of the matrix and the vector

**Usage/Example:** The following lines of code compute the produt of a matrix and a vector, and the main function tests the method
	
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
    vector<double> Ax = matVecMul(A, x, 3, 3);

    for(int i = 0; i < 3; i++)
    {
      cout << Ax[i] << " ";
    }
	
The output follows

    3 6 9

**Implementation/Code:** The following is the code for matVecMul and the main function to run the method

    #include <iostream>
    #include <vector>

    using namespace std;

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
      vector<double> Ax = matVecMul(A, x, 3, 3);

      for(int i = 0; i < 3; i++)
      {
        cout << Ax[i] << " ";
      }

      return 0;
    }

**Last Modified: December 2018**
