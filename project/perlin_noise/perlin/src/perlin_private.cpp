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
  int crows = nrows - 1;
  int ccols = ncols - 1;
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

ndvector<1,int>::t
Perlin::_get_current_cell(ndvector<1,double>::t const &p, int const &nrows, int const &ncols, double const &step)
{
  // Indices of the current cell
  int ix = (int)(p[0] / step);
  int iy = (int)(p[1] / step);
  // Correct for points on borders
  if(ix == ncols-1) { ix = ncols-2; }
  if(iy == nrows-1) { iy = nrows-2; }

  return(_cell_corners[iy * (ncols-1) + ix]);
}

double
Perlin::_interpolate(double const &d0, double const &d1, double const &w) {
  /*

  Value of the weight `w` should be in the interval [0,1]
  */

  // Simple interpolation between two values
  //return( (d1 - d0) * w + d0 );

  // Use this cubic interpolation [[Smoothstep]] instead, for a smooth appearance:
  //return( (d1 - d0) * (3.0 - w * 2.0) * w * w + d0 );

  // Use [[Smootherstep]] for an even smoother result with a second derivative equal to zero on boundaries:
  return( (d1 - d0) * ((w * (w * 6.0 - 15.0) + 10.0) * w * w * w) + d0 );
}