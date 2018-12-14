# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           KroeProd

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the Kroenecker product between two matrices

**Input:** The inputs are two vector of vector of doubles, A and B, and the dimensions n, m of A and p, q of B

**Output:** This routine returns a vector of vector of doubles, the Kroenecker product of A and B

**Usage/Example:** The following lines of code compute the Kroenecker product of two matrices A and B in the main function

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

    vector<vector<double>> B;

    for(int i = 0; i < 2; i++)
    {
      vector<double> row;
      for(int j = 0; j < 2; j++)
      {
        row.push_back(i + 1);
      }
      B.push_back(row);
    }
	
	vector<vector<double>> AxB = KroeProd(A, B, 3, 3, 2, 2);
	
The output follows

    1 1 1 1 1 1
    1 1 1 1 1 1
    2 2 2 2 2 2
    2 2 2 2 2 2
    3 3 3 3 3 3
    3 3 3 3 3 3

**Implementation/Code:** The following is the code for KroeProd and the main function to run the method

    #include <iostream>
    #include <vector>
    #include <math.h>

    using namespace std;

    // A is n x m, B is p x q, A x B is np x mq
    vector<vector<double>> KroeProd(vector<vector<double>> A, vector<vector<double>> B, int n, int m, int p, int q)
    {
      vector<vector<double>> ans;

      for(int i = 0; i < n; i++)
      {
        vector<double> row;
        for(int k = 0; k < p; k++)
        {
          for(int j = 0; j < m; j++)
          {
            for(int l = 0; l < q; l++)
            {
              row.push_back(A[i][j] * B[k][l]);	
            }
          }
          ans.push_back(row);
        }
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

      vector<vector<double>> B;

      for(int i = 0; i < 2; i++)
      {
        vector<double> row;
        for(int j = 0; j < 2; j++)
        {
          row.push_back(i + 1);
        }
        B.push_back(row);
      }

      vector<vector<double>> AxB = KroeProd(A, B, 3, 3, 2, 2);

      return 0;
    }

**Last Modified: December 2018**
