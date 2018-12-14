# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           matOutProd

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the outer product between two matrices

**Input:** The inputs are two vector of vector of doubles, A and B, and the dimensions n and m of the matrices

**Output:** This routine returns a vector of vector of doubles, the outer product of A and B

**Usage/Example:** The following lines of code compute the outer product of two matrices A and B in the main function

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

    vector<vector<double>> AB = matOutProd(A, A, 3, 3);

    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        cout << AB[i][j] << " ";
      }
      cout << endl;
    }
	
The output follows

    3 6 9
    6 12 18
    9 18 27

**Implementation/Code:** The following is the code for matOutProd and the main function to run the method

    #include <iostream>
    #include <vector>
    #include <math.h>

    using namespace std;

    vector<vector<double>> matOutProd(vector<vector<double>> A, vector<vector<double>> B, int n, int m)
    {
      vector<vector<double>> Bt = transpose(B, m, n);

      return matMul(A, Bt, n, m);
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

      vector<vector<double>> AB = matOutProd(A, A, 3, 3);

      for(int i = 0; i < 3; i++)
      {
        for(int j = 0; j < 3; j++)
        {
          cout << AB[i][j] << " ";
        }
        cout << endl;
      }

      return 0;
    }

**Last Modified: December 2018**
