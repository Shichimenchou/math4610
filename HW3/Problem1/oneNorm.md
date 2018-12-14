# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           bisection

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

**Description/Purpose:** This routine will compute the 1-norm of a vector

**Input:** The inputs a vector of doubles v, and an integer length of v

**Output:** This routine returns a double value: the 1-norm of v

**Usage/Example:** These two lines of code in the main function call the program

	vector<double> v = { 1, 1, 1, 1, 1 };
	cout << oneNorm(v, 5) << endl;
	
The output of running this code is below:

	5
	
This is exactly correct

**Implementation/Code:** The following is the code for oneNorm and the main function to run the code

	double oneNorm(vector<double> v, int length)
	{
		double sum = 0.0;

		for (int i = 0; i < length; i++)
		{
			sum += v[i];
		}

		return sum;
	}

	int main()
	{
		vector<double> v = { 1, 1, 1, 1, 1 };
		cout << oneNorm(v, 5) << endl;

		return 0;
	}

**Last Modified: December 2018**
