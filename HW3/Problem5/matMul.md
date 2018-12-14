# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           matMul

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the product of two matrices

**Input:** The inputs two vector of vector of doubles, A and B, and the dimension of matrix A, n and m

**Output:** This routine returns a matrix, the product of the two matrices

**Usage/Example:** The following lines of code compute the produt of the matrices, and the main function tests the method
	
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

    vector<vector<double>> AA = matMul(A, A, 3, 3);

    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        cout << AA[i][j] << " ";
      }
      cout << endl;
    }
	
The output follows

    6 6 6
    12 12 12
    18 18 18

**Implementation/Code:** The following is the code for matMul and the main function to run the method

    #include <iostream>
    #include <vector>

    using namespace std;

    // A is n x m, B is m x n, so the ans is n x n
    vector<vector<double>> matMul(vector<vector<double>> A, vector<vector<double>> B, int n, int m)
    {
      vector<vector<double>> ans;

      for(int i = 0; i < n; i++)
      {
        vector<double> row;
        for(int j = 0; j < m; j++)
        {
          double val = 0.0;
          for(int k = 0; k < m; k++)
          {
            val += A[i][k] * B[k][j];
          }		
          row.push_back(val);
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

      vector<vector<double>> AA = matMul(A, A, 3, 3);

      for(int i = 0; i < 3; i++)
      {
        for(int j = 0; j < 3; j++)
        {
          cout << AA[i][j] << " ";
        }
        cout << endl;
      }

      return 0;
    }

**Last Modified: December 2018**
