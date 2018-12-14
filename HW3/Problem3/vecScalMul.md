# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           vecScalMul

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will multiply a vector by a scalar

**Input:** The inputs are vector of doubles x, and a scalar y, and the length of the vector int length

**Output:** This routine returns a vector of doubles yx

**Usage/Example:** The following lines of code compute in the main function compute give the values of the entries in the new vector

    vector<double> x;
    double y = 5.0;	
    x.push_back(1);
    x.push_back(1);
    x.push_back(1);
    x.push_back(1);
    x.push_back(1);	

    cout << vecScalMul(x, y, 5)[0] << endl;
    cout << vecScalMul(x, y, 5)[1] << endl;
    cout << vecScalMul(x, y, 5)[2] << endl;
    cout << vecScalMul(x, y, 5)[3] << endl;
    cout << vecScalMul(x, y, 5)[4] << endl;
	
The output follows

    5.0
    5.0
    5.0
    5.0
    5.0

**Implementation/Code:** The following is the code for vecScalMul and the main function to run the method

	  #include <iostream>
	  #include <vector>

	  using namespace std;


    vector<double> vecScalMul(vector<double> x, double y, int length)
    {
      vector<double> xy;

      for(int i = 0; i < length; i++)
      {
        xy.push_back( x[i] * y);
      }

      return xy;
    }

	  int main()
	  {
	    vector<double> x;
	    double y = 5.0;
	    x.push_back(1);
	    x.push_back(1);
	    x.push_back(1);
	    x.push_back(1);
	    x.push_back(1);	

	    cout << vecScalMul(x, y, 5)[0] << endl;
	    cout << vecScalMul(x, y, 5)[1] << endl;
	    cout << vecScalMul(x, y, 5)[2] << endl;
	    cout << vecScalMul(x, y, 5)[3] << endl;
	    cout << vecScalMul(x, y, 5)[4] << endl;

	    return 0;
	  }

**Last Modified: December 2018**
