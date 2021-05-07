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

#include <vector>

#include <template.hpp>
#include <perlin.hpp>

// Generate a 2D coordinate grid between given X and Y limits
ndvector<2,double>::t
Perlin::_get_coordinates(int const &nrows, int const &ncols,
                         double const &stepx, double const &stepy)
{
  // Declaration of the coordinate grid
  ndvector<2,double>::t coords (nrows * ncols);

  // Calculate coordinates of grid points
  for(int i = 0; i < nrows; i++)
  {
    for(int j = 0; j < ncols; j++)
    {
      coords[i * ncols + j] = {j*stepx, i*stepy};
    }
  }

  return(coords);
}

// Get indices of the main grid points in main cell corners per cells
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

// Get indices of the sub grid points in sub cell corners per cells
ndvector<2,int>::t
Perlin::_set_sub_cell_corners(int const &nrows, int const &ncols, int const &res)
{
  // Number of cells in each rows and columns
  int crows = (nrows - 1)*res;
  int ccols = (ncols - 1)*res;
  ndvector<2,int>::t sub_cell_corners (crows * ccols);

  // Iterate over all points, except the last row and the last column.
  // The iteration is basically over the possible upper left corners for a cell.
  for(int i = 0; i < crows; i++)
  {
    for(int j = 0; j < ccols; j++)
    {
      int idx = i * ccols + j; // Index for cells
      int c = i * (ccols+1) + j;   // Index for coordinates
      
      // Gather the coordinates of cell's corners.
      // Coordinates are in the upper right quarter of the coordinate system
      // and they're situated in the following order in the `sub_cell_corners` vector:
      // 1: Bottom left
      // 2: Bottom right
      // 3: Upper left
      // 4: Upper right
      // (ccols + 1) = the number of columns in the sub grid
      sub_cell_corners[idx] = {c, c+1, c+ccols+1, c+ccols+2};
    }
  }

  return(sub_cell_corners);
}

double
Perlin::_interpolate(double const &d0, double const &d1, double const &w) {
  /*

  Value of the weight `w` should be in the interval [0,1]
  */

  // Simple interpolation between two values
  //return( (d1 - d0) * w + d0 );

  // Use this cubic interpolation [[Smoothstep]] instead, for a smooth appearance
  //return( (d1 - d0) * (3.0 - w * 2.0) * w * w + d0 );

  // Use [[Smootherstep]] for an even smoother result with a second derivative
  // equal to zero on boundaries
  return( (d1 - d0) * ((w * (w * 6.0 - 15.0) + 10.0) * w * w * w) + d0 );
}