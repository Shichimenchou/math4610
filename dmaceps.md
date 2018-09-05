# Math 4610 Fundamentals of Computational Mathematics Software Manual

**Routine Name:**           dmaceps

**Author:** Phillip Linson

**Language:** C++. The code can be compiled using g++.

For example,

    g++ dmaceps.cpp

will produce an **./a.out** file.

**Description/Purpose:** This routine will compute the double precision value for the machine epsilon or the number of digits
in the representation of real numbers in double precision. This is a routine for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** There are no inputs needed in this case. Even though there are arguments supplied, the real purpose is to
return values in those variables.

**Output:** This routine returns a double precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

The routine has two arguments needed to return the values of the precision in terms of the smallest number that can be
represented. The first argument is a double precision value (double) and the second is an integer. The new values for these
variables is then printed using cout.

      smaceps(sval, ipow);
      cout << ipow << " " << sval << endl;

Output from the lines above:

      53 1.11022e-16

The first value (53) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (e-08 on the
end of the second value).

**Implementation/Code:** The following is the code for smaceps()

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
        between one and the approximation is zero in double precision
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

**Last Modified:** September/2018
