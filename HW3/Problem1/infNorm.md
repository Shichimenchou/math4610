# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           infNorm

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will compute the infinity-norm of a vector

**Input:** The inputs a vector of doubles v, and an integer length of v

**Output:** This routine returns a double value: the infinity-norm of v

**Usage/Example:** These two lines of code in the main function call the program

	vector<double> v = { 1, 1, 1, 1, 1 };
	cout << infNorm(v, 5) << endl;
	
The output of running this code is below:

	1
	
This is correct

**Implementation/Code:** The following is the code for infNorm and the main function to run the code

	
	double infNorm(vector<double> v, int length)
	{
		double max = 0.0;

		for (int i = 0; i < length; i++)
		{
			if (abs(v[i]) > max)
			{
				max = abs(v[i]);
			}
		}

		return max;
	}

	int main()
	{
		vector<double> v = { 1, 1, 1, 1, 1 };
		cout << infNorm(v, 5) << endl;

		return 0;
	}

**Last Modified: December 2018**
