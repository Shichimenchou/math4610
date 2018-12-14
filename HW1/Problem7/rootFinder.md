# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           rootFinder

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

For example,

    g++ rootFinder.cpp

will produce an **./a.out** file.

**Description/Purpose:** This program will find real or imaginary roots for second order polynomials.

**Input:** The coefficients of the x^2 term (a), x term (b), and constant term (c).

**Output:** This program returns a fractional representation of each root, as well as the numerical value for each root.

**Usage/Example:**

Upon executing the program, the user is greeted with a prompt asking for input and specifying format:

      Input values a, b, and c in the polynomial ax^2 + bx + c = 0 (format a b c) : 

Entering, for example,
      
      1 -2 1
      
then hitting return will return the following output derived from the quadratic equation:

      The two roots are : 2/2 = 1 and 2/2 = 1
      
Thes are simple representations of the numerator and denominator of each root, as calculated directly from the quadratic equation
on the left hand side of each equation and a more simplified number on the right hand side.

**Implementation/Code:** The following is the code for smaceps()

      #include <iostream>
      #include <cmath>

      using namespace std;

      int main()
      {
        double a, b, c;

        cout << "Input values a, b, and c in the polynomial ax^2 + bx + c = 0 (format: a b c) : ";
        cin >> a >> b >> c;

        double num1, num2, den1, den2;
        bool imag = false;

        if(b * b - 4 * a * c < 0)
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

**Last Modified:** September/2018
