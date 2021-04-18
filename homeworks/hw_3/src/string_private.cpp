////////////////////////////////////////////////////////
//
//    Numerical integration
//
//    File : string_private.cpp
//    Desc : Contains definition to the private methods
//           of `String` class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <math.h>

#include <string.hpp>

double
String::_get_value(double const &x)
{
  return F/q * ( cosh(q/F * x) - cosh(q*a / 2 / F) ) + h;
}