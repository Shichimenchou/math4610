# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           det2 and detN

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will calculate the determinant of a square matrix

**Input:** The inputs are a vector of vector of doubles A, and the dimension of A, n

**Output:** This routine returns double, det(A)

**Usage/Example:** The following lines of code compute the determinant of A in the main function

	vector<vector<double>> C;
	
	for(int i = 0; i < 3; i++)
	{
		vector<double> row;
		for(int j = 0; j < 3; j++)
		{
			row.push_back(i + j);
		}
		C.push_back(row);
	}
	
	cout << detN(C, 3);
	
The output follows

    0

**Implementation/Code:** The following is the code for KroeProd and the main function to run the method

    #include <iostream>
    #include <vector>
    #include <math.h>

    using namespace std;

    double det2(vector<vector<double>> A)
    {
      return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }

    double detN(vector<vector<double>> A, int n)
    {
      while(n > 2)
      {
        vector<vector<double>> smaller;
        for(int i = 0; i < n - 1; i++)
        {
          vector<double> row;
          for(int j = 0; j < n - 1; j++)
          {
            row.push_back(0.0);
          }
          smaller.push_back(row);
        }

        for(int i = 0; i < n; i++)
        {
          vector<vector<double>> temp;
          for(int j = 0; j < n; j++)
          {
            if(j != i)
            {
              vector<double> row;
              for(int k = 0; k < n; k++)
              {
                if(k!= i)
                {
                  row.push_back(A[i][i] * A[j][k] * pow(-1, (i % 2) + 1));
                }

              }
              temp.push_back(row);
            }
          }

          smaller = matAdd(smaller, temp, n-1, n-1);
        }
        n--;
        if(n == 2)
        {
          return det2(smaller);	
        }
        else
        {
          A = smaller;
        }
      }
      return -1000000;
    }

    int main()
    {
      vector<vector<double>> C;

      for(int i = 0; i < 3; i++)
      {
        vector<double> row;
        for(int j = 0; j < 3; j++)
        {
          row.push_back(i + j);
        }
        C.push_back(row);
      }

      cout << detN(C, 3);

      return 0;
    }

**Last Modified: December 2018**
