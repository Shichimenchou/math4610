#include <iostream>
#include <cmath>

using namespace std;

/*
	Since this is a simple program it is just implemented in the main function
	-------------------------------------------------------------------------- 
*/
int main()
{
	/*
		Declare then take in values for the coefficients of the polynomial
	*/
	double a, b, c;
	cout << "Input values a, b, and c in the polynomial ax^2 + bx + c = 0 (format: a b c) : ";
	cin >> a >> b >> c;

	double num1, num2, den1, den2;
	
	/*
		Determine if the the 
	*/
	bool imag = false;
	if(b * b - 4 * a * c < 0)
		imag = true;	
		imag = true;	

	if(imag)
		num1 = -b + sqrt(- b * b + 4 * a * c);
	else
		num1 = -b + sqrt(b * b - 4 * a * c);
	den1 = 2 * a;
	
	if(imag)
		num2 = -b - sqrt(- b * b + 4 * a * c);
	else
		num2 = -b - sqrt(b * b - 4 * a * c);
	den2 = 2 * a;

	if(imag)
		cout << "The two roots are : " << num1 << "i/" << den1 << " = " << num1/den1  << "i and " << num2 << "i/" << den2 << " = " << num2 / den2 << "i" << endl;
	else
		cout << "The two roots are : " << num1 << "/" << den1 << " = " << num1/den1  << " and " << num2 << "/" << den2 << " = " << num2 / den2 << endl;

	return 0;
}
