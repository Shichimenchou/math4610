# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           backSub

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will use back substitution to find x for the system Ax = b, where A is upper-triangular

**Input:** The inputs are a vector of vector of doubles A, a vector of doubles b, and the dimension of A, n

**Output:** This routine returns a vector of doubles, the solution x to the system Ax = b

**Usage/Example:** This code from the main function creates an example A and b and prints the solution x

    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    vector<double> backSub(vector<vector<double>> A, vector<double> b, int n)
    {
      bool flag = false;
      for(int i = 0; i < n; i++)
      {
        if(A[i][i] == 0)
        {
          flag = true;
          break;
        }
      }
      if(flag)
      {
        vector<double> error;
        for(int i = 0; i < n; i++)
        {
          error.push_back(-1000000.0);
        }
        return error;
      }
      vector<double> soln;
      double sum;
      for(int i = n-1; i >= 0; i--)
      {
        sum = 0.0;
        for(int j = n-1; j > i; j--)
        {
          sum += soln[n - j - 1] * A[i][j];
        }
        soln.push_back((b[i] - sum) / A[i][i]);
      }

      reverse(soln.begin(), soln.end());
      return soln;
    }

    int main()
    {
      vector<vector<double>> A;
      vector<double> row1;vector<double> row2;vector<double> row3; vector<double> row4;
      row1.push_back(4);row1.push_back(-1);row1.push_back(2);row1.push_back(3);		
      row2.push_back(0);row2.push_back(-2);row2.push_back(7);row2.push_back(-4);	
      row3.push_back(0);row3.push_back(0);row3.push_back(6);row3.push_back(5);	
      row4.push_back(0);row4.push_back(0);row4.push_back(0);row4.push_back(3);
      A.push_back(row1);A.push_back(row2);A.push_back(row3);A.push_back(row4);

      vector<double> b;
      b.push_back(20);b.push_back(-7);b.push_back(4);b.push_back(6);

      vector<double> x = backSub(A, b, 4);

      for(int i = 0; i < 4; i++)
      {
        cout << x[i] << " "; 
      }

      return 0;
    }

**Last Modified: December 2018**
