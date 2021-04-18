////////////////////////////////////////////////////////
//
//    Numerical integration
//
//    File : vector.hpp
//    Desc : Contains some methods to handle the positions,
//           values and other parameters stored as vectors
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <vector>

std::vector<double>
get_X(int const &N, double const &a, double const &b)
{
  // Determine the x_n sampling points
  std::vector<double> X (N);
  // Determine the step size between sampling points
  double step = (b-a) / (N-1);
  // Set the N-2 intermediate points
  for(int i = 0; i < N; i++)
  {
    X[i] = i * step;
  }

  return X;
}