# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           forwardSub

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will use forward substitution to find x for the system Ax = b, where A is lower-triangular

**Input:** The inputs are a vector of vector of doubles A, a vector of doubles b, and the dimension of A, n

**Output:** This routine returns a vector of doubles, the solution x to the system Ax = b

**Usage/Example:** This code from the main function creates an example A and b and prints the solution x

      vector<vector<double>> A;
      vector<double> row1;vector<double> row2;vector<double> row3; vector<double> row4;
      row1.push_back(3);row1.push_back(0);row1.push_back(0);row1.push_back(0);		
      row2.push_back(-1);row2.push_back(1);row2.push_back(0);row2.push_back(0);	
      row3.push_back(3);row3.push_back(-2);row3.push_back(-1);row3.push_back(0);	
      row4.push_back(1);row4.push_back(-2);row4.push_back(6);row4.push_back(2);
      A.push_back(row1);A.push_back(row2);A.push_back(row3);A.push_back(row4);

      vector<double> b;
      b.push_back(5);b.push_back(6);b.push_back(4);b.push_back(2);

      vector<double> x = forwardSub(A, b, 4);

      for(int i = 0; i < 4; i++)
      {
        cout << x[i] << " "; 
      }

The output follows

    1.66667 7.66667 -14.3333 50.8333
    
This solution is correct
 
**Implementation/Code:** The following is the code for forwardSub and the main function to run the method

    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    vector<double> forwardSub(vector<vector<double>> A, vector<double> b, int n)
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
      for(int i = 0; i < n; i++)
      {
        sum = 0.0;
        for(int j = 0; j < i; j++)
        {
          sum += (soln[j] * A[i][j]);
          //cout << i <<  soln[j] << " " << A[i][j] << endl;
          //cout << sum << endl;
        }
        soln.push_back((b[i] - sum) / A[i][i]);
      }

      return soln;
    }

    int main()
    {
      vector<vector<double>> A;
      vector<double> row1;vector<double> row2;vector<double> row3; vector<double> row4;
      row1.push_back(3);row1.push_back(0);row1.push_back(0);row1.push_back(0);		
      row2.push_back(-1);row2.push_back(1);row2.push_back(0);row2.push_back(0);	
      row3.push_back(3);row3.push_back(-2);row3.push_back(-1);row3.push_back(0);	
      row4.push_back(1);row4.push_back(-2);row4.push_back(6);row4.push_back(2);
      A.push_back(row1);A.push_back(row2);A.push_back(row3);A.push_back(row4);

      vector<double> b;
      b.push_back(5);b.push_back(6);b.push_back(4);b.push_back(2);

      vector<double> x = forwardSub(A, b, 4);

      for(int i = 0; i < 4; i++)
      {
        cout << x[i] << " "; 
      }

      return 0;
    }

**Last Modified: December 2018**
