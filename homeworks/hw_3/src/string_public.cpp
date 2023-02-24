////////////////////////////////////////////////////////
//
//    Numerical integration
//
//    File : string_public.cpp
//    Desc : Contains definition to the public methods
//           of `String` class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <math.h>
#include <vector>

#include <string.hpp>
#include <richardson.hpp>

double
String::f(double const &x)
{
  return F/q * ( cosh(q/F * x) - cosh(q*b / 2 / F) ) + h;
}

double
String::fprime(double const &x)
{
  /*
  Calculates the prime of a function at location `x` using 
  */
  // Determine the step size between sampling points
  double step = (b-a) / (N-1);

  return R_6(*this, x, step);
}

double
String::dL(double const &x)
{
  /*
  Calculates the length of the unit line segment.

  dL = sqrt( 1 + f'(x)^2 )

  The derivatives are approximated using the 6th order Richardson method
  */

  double Fprime = fprime(x);
  double dL = sqrt( 1 + Fprime*Fprime );

  return dL;
}