////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : perlin_public.cpp
//    Desc : Contains the definition to the public methods
//           of the `Perlin` class
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <random>
#include <vector>
#include <algorithm>

#include <template.hpp>
#include <perlin.hpp>

// Create a discrete vector field of vectors with randomly choosen
// arguments. Vectors are situated in each gridpoints.
void
Perlin::set_main_grid(int const &nrows, int const &ncols, double const &step)
{
  _main_grid = _get_coordinates(nrows, ncols, step);
}

// Create a discrete vector field of vectors with randomly choosen
// arguments. Vectors are situated in each gridpoints.
void
Perlin::set_gradient_field(int const &nrows, int const &ncols)
{
  // Initialize the Mersenne-Twister RNG to choose
  // values from a uniform distribution between 0 and 2pi
  std::random_device Randomized;
  std::mt19937_64 Generate(Randomized());
  std::uniform_real_distribution<> Distribution(0, 2*pi());

  // Placeholder for the gradient field
  ndvector<2,double>::t gradient_field (nrows * ncols);

  // Generate the gradient field
  for(int i = 0; i < nrows; i++)
  {
    for(int j = 0; j < ncols; j++)
    {
      double phi = Distribution(Generate);
      gradient_field[i * ncols + j] = _get_gradient(phi);
    }
  }

  _gradient_field = gradient_field;
}

// Create sub-cells in which dot products are evaluated
void
Perlin::set_sub_grid(int const &nrows, int const &ncols, double const &step, double const &res)
{
  _sub_grid = _get_coordinates(nrows*res, ncols*res, step/res);
  _cell_corners = _set_cell_corners(nrows, ncols);
}

// Get the dot product of the sub grid vectors and the nearest main grid vectors
void
Perlin::set_dot_grid(int const &nrows, int const &ncols, double const &step, double const &res)
{

  // Placeholder for the dot product field
  ndvector<2,double>::t dot_grid (
                                    ncols * nrows * (res*res),
                                    ndvector<1,double>::t (4)
                                 );

  int sub_i = 0;
  int sub_c_i = 0;
  for(auto const& p : std::as_const(_sub_grid))
  {
    int ix = (int)(p[0] / step);
    int iy = (int)(p[1] / step);
    // Correct for points on borders
    if(ix == ncols) { ix = ncols-1; }
    if(iy == nrows) { iy = nrows-1; }
    auto cc = _cell_corners[iy * ncols + ix];

    sub_c_i = 0;
    for(auto const& c_i : std::as_const(cc))
    {
      // Current main grid point (which is one of the corners to the current cell)
      auto c = _main_grid[c_i];
      // Placeholder for the current distance vector
      ndvector<1,double>::t d (2);

      // Calculate distance between vectors `c` and `p`: d = c - p
      std::transform(c.begin(), c.end(), p.begin(), d.begin(),
                     std::minus<double>());
      
      // Add dot product of distance vector and gradient in corner to the dot field
      auto grad = _gradient_field[c_i];
      dot_grid[sub_i][sub_c_i] = std::inner_product(d.begin(), d.end(), grad.begin(), 0.0);

      sub_c_i++;
    }

    sub_i++;
  }

  _dot_grid = dot_grid;
}