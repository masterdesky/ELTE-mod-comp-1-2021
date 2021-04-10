////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : perlin_private.cpp
//    Desc : Contains the definition to the private methods
//           of the `Perlin` class
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <math.h>
#include <vector>
#include <template.hpp>
#include <perlin.hpp>

// Generate a 2D coordinate grid between given X and Y limits
ndvector<2,double>::t
Perlin::_get_coordinates(int const &nrows, int const &ncols, double const &step)
{
  // Declaration of the coordinate grid
  ndvector<2,double>::t coords (nrows * ncols);

  // Limits
  //ndvector<1,double> X = { 0, nrows*step };
  //ndvector<1,double> Y = { 0, ncols*step };

  // Calculate coordinates of grid points
  for(int i = 0; i < nrows; i++)
  {
    for(int j = 0; j < ncols; j++)
    {
      coords[i * ncols + j] = {j*step, i*step};
    }
  }

  return(coords);
}


// Return a 2D vector with a given `phi` argument
ndvector<1,double>::t
Perlin::_get_gradient(double const &phi)
{
  ndvector<1,double>::t gradient {sin(phi), cos(phi)};

  return(gradient);
}