#include <iostream>
#include <cmath>

using namespace std;

void dmaceps(double& meps, int& ipow)
{
/*
	set up storage for the algorithm
	--------------------------------
*/
	double one, appone;

/*
	initialize variables to compute the machine value near 1.0
	----------------------------------------------------------
*/
	one = 1.0;
	meps = 1.0;
	appone = one + meps;

/*
	loop, dividing by 2 each time to determine when the difference
	between one and the approximation is zero in single precision
	-------------------------------------------------------------
*/
	ipow = 0;
	for(int i = 0; i < 1000; i++)
	{
		ipow++;

/*
	update the perturbation and compute the approximation to one
	------------------------------------------------------------
*/
		meps /= 2;
		appone = one + meps;
	
/*
	do the comparison and if small enough, break out of the loop
	and return contorl the the calling code
	---------------------------------------
*/	
		if(abs(appone - one) == 0.0)
			return;
	}

/*
	if the code gets to this point, there is a bit of trouble
	---------------------------------------------------------
*/

	cout << "The loop limit has been exceeded" << endl;
}

int main(int argc, char** argv)
{
	double dval;
	int ipow;

	dmaceps(dval, ipow);
	cout << ipow << " " << dval << endl;
}
