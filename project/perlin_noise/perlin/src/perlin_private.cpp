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

// Get indices of the main grid points in cell corners per cells
ndvector<2,int>::t
Perlin::_set_cell_corners(int const &nrows, int const &ncols)
{
  // Number of cells in each rows and columns
  int crows = nrows;
  int ccols = ncols;
  ndvector<2,int>::t cell_corners (crows * ccols);

  // Iterate over all points, except the last row and the last column.
  // The iteration is basically over the possible upper left corners for a cell.
  for(int i = 0; i < crows; i++)
  {
    for(int j = 0; j < ccols; j++)
    {
      int idx = i * ccols + j; // Index for cells
      int c = i * ncols + j;   // Index for coordinates
      
      // Gather the coordinates of cell's corners.
      // Coordinates are in the upper right quarter of the coordinate system
      // and they're situated in the following order in the `cell_corners` vector:
      // 1: Bottom left
      // 2: Bottom right
      // 3: Upper left
      // 4: Upper right
      cell_corners[idx] = {c, c+1, c+ncols, c+ncols+1};
    }
  }

  return(cell_corners);
}