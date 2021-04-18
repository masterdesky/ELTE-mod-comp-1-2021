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

#include <vector>

#include <string.hpp>

std::vector<double>
String::sample(std::vector<double> const &X)
{
  /*
  Samples N points from the values of the curve.
  */
  int N = static_cast<int>(X.size());

  // Placeholder for the sampled values
  std::vector<double> Y (N);

  int t = 0;
  for(auto const &x_i : std::as_const(X))
  {
    Y[t] = _get_value(x_i);
    t++;
  }

  return Y;
}