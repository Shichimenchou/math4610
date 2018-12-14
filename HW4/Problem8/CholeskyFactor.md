# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           CholeskyFactor

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will use the Cholesky Factorization to find L such that M = LL^T

**Input:** The inputs are a vector of vector of doubles M, and the dimension of M, n

**Output:** This routine returns a vector of vector of doubles, the matrix L

**Usage/Example:** This code from the main function creates two symmetric positive-definite matrices and runs CholeskyFactor on them

            vector<vector<double>> A;
            vector<double> row1;vector<double> row2;vector<double> row3;
            row1.push_back(4);row1.push_back(12);row1.push_back(-16);
            row2.push_back(12);row2.push_back(37);row2.push_back(-43);
            row3.push_back(-16);row3.push_back(-43);row3.push_back(98);
            A.push_back(row1);A.push_back(row2);A.push_back(row3);

            vector<vector<double>> L = CholeskyFactor(A, 3);

            for(int i = 0; i < 3; i++)
            {
                  for(int j = 0; j < 3; j++)
                  {
                        cout << L[i][j] << " ";
                  }
                  cout << endl;
            }
            cout << endl;

            vector<vector<double>> B;
            for(int i = 0; i < 5; i++)
            {
                  vector<double> row;
                  for(int j = 0; j < 5; j++)
                  {
                        row.push_back(1.0/(i + j + 1.0));
                  }
                  B.push_back(row);
            }

            vector<vector<double>> L2 = CholeskyFactor(B, 5);

            for(int i = 0; i < 5; i++)
            {
                  for(int j = 0; j < 5; j++)
                  {
                        cout << L2[i][j] << " ";
                  }
                  cout << endl;
            }
      
The output follows

    2 0 0 
    6 1 0
    -8 5 3
    
    1 0 0 0 0
    0.5 0.2888675 0 0 0
    0.333333 0.2888675 0.0745356 0 0
    0.25 0.259808 0.111803 0.01888982 0
    0.2 0.23094 0.127775 0.0377964 0.0047619
    
Taking the tranpose of these matrices and multiplying them with their pair gives the exact matrix M in the first case, and a good approximation in the second case
 
**Implementation/Code:** The following is the code for CholeskyFactor and the main function to run the method

      #include <iostream>
      #include <vector>
      #include <math.h>

      using namespace std;

      vector<vector<double>> CholeskyFactor(vector<vector<double>> M, int n)
      {
            vector<vector<double>> L;
            double sum = 0.0;

            for(int i = 0; i < n; i++)
            {
                  vector<double> row;
                  for(int j = 0; j < n; j++)
                  {
                        row.push_back(0.0);
                  }
                  L.push_back(row);
            }

            for(int i = 0; i < n; i++)
            {
                  for(int j = 0; j < n; j++)
                  {
                        sum = 0.0;
                        if(i == j)
                        {
                              sum += M[i][j];
                              for(int k = 0; k < j; k++)
                              {
                                    sum -= L[j][k] * L[j][k];
                              }
                              L[i][j] = sqrt(sum);
                        }
                        else if(j < i)
                        {
                              sum += M[i][j];
                              for(int k = 0; k < j; k++)
                              {
                                    sum -= L[i][k] * L[j][k];
                              }
                              L[i][j] = sum / L[j][j];
                        }
                  }
            }

            return L;
      }

      int main()
      {
            vector<vector<double>> A;
            vector<double> row1;vector<double> row2;vector<double> row3;
            row1.push_back(4);row1.push_back(12);row1.push_back(-16);
            row2.push_back(12);row2.push_back(37);row2.push_back(-43);
            row3.push_back(-16);row3.push_back(-43);row3.push_back(98);
            A.push_back(row1);A.push_back(row2);A.push_back(row3);

            vector<vector<double>> L = CholeskyFactor(A, 3);

            for(int i = 0; i < 3; i++)
            {
                  for(int j = 0; j < 3; j++)
                  {
                        cout << L[i][j] << " ";
                  }
                  cout << endl;
            }
            cout << endl;

            vector<vector<double>> B;
            for(int i = 0; i < 5; i++)
            {
                  vector<double> row;
                  for(int j = 0; j < 5; j++)
                  {
                        row.push_back(1.0/(i + j + 1.0));
                  }
                  B.push_back(row);
            }

            vector<vector<double>> L2 = CholeskyFactor(B, 5);

            for(int i = 0; i < 5; i++)
            {
                  for(int j = 0; j < 5; j++)
                  {
                        cout << L2[i][j] << " ";
                  }
                  cout << endl;
            }

            return 0;
      }

**Last Modified: December 2018**
