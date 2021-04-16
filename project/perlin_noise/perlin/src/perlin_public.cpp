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
  double sub_step = step/res;
  _sub_grid = _get_coordinates((nrows-1)*res+1, (ncols-1)*res+1, sub_step);
  _cell_corners = _set_cell_corners(nrows, ncols);
}

// Get the dot product of the sub grid vectors and the nearest main grid vectors
void
Perlin::set_dot_grid(int const &nrows, int const &ncols, double const &step, double const &res)
{

  // Placeholder for the dot product field
  ndvector<2,double>::t dot_grid (
                                    ((nrows-1)*res+1) * ((ncols-1)*res+1),
                                    ndvector<1,double>::t (4)
                                 );

  // Placeholder for the indices of the nearest main grid points for every
  // sub grid point
  ndvector<1,int>::t ngp (((nrows-1)*res+1) * ((ncols-1)*res+1));

  int sub_i = 0;
  int sub_c_i = 0;
  for(auto const& p : std::as_const(_sub_grid))
  {
    int ix = (int)(p[0] / step);
    int iy = (int)(p[1] / step);
    // Correct for points on borders
    if(ix == ncols-1) { ix = ncols-2; }
    if(iy == nrows-1) { iy = nrows-2; }

    auto cc = _cell_corners[iy * (ncols-1) + ix];

    sub_c_i = 0;
    double ngp_val = step + 1;
    for(auto const &c_i : std::as_const(cc))
    {
      // Current main grid point (which is one of the corners to the current cell)
      auto c = _main_grid[c_i];
      // Placeholder for the current distance vector
      ndvector<1,double>::t d (2);

      // Calculate distance between vectors `c` and `p`: d = c - p
      std::transform(c.begin(), c.end(), p.begin(), d.begin(),
                     std::minus<double>());

      // Check whether if this corner is the closest to the sub grid point
      double dist = sqrt(d[0]*d[0] + d[1]*d[1]);
      if(dist < ngp_val)
      {
        ngp_val = dist;
        ngp[sub_i] = sub_c_i;
      } 
      
      // Add dot product of distance vector and gradient in corner to the dot field
      auto grad = _gradient_field[c_i];
      dot_grid[sub_i][sub_c_i] = std::inner_product(d.begin(), d.end(), grad.begin(), 0.0);

      sub_c_i++;
    }

    sub_i++;
  }

  _dot_grid = dot_grid;
  _ngp = ngp;
}

void
Perlin::set_interp_grid(int const &nrows, int const &ncols, double const &res)
{
  ndvector<1,double>::t interp_grid (((ncols-1)*res+1) * ((nrows-1)*res+1));

  // Weight for the interpolation
  double w = 0.5;

  int idx = 0;
  for(auto const& dd : std::as_const(_dot_grid))
  {
    // Determine interpolation weights
    // Could also use higher order polynomial/s-curve here
    //float sx = x - (float)x0;
    //float sy = y - (float)y0;

    auto i_1 = _interpolate(dd[0], dd[1], w);
    auto i_2 = _interpolate(dd[2], dd[3], w);

    interp_grid[idx] = _interpolate(i_1, i_2, w);
    idx++;
  }

  _interp_grid = interp_grid;
}