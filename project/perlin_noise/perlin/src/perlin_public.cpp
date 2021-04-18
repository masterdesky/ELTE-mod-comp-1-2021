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
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_real_distribution<> Distribution(0, 2*pi());

  // Placeholder for the gradient field
  ndvector<2,double>::t gradient_field (nrows * ncols);

  // Generate the gradient field
  for(int i = 0; i < nrows; i++)
  {
    for(int j = 0; j < ncols; j++)
    {
      double phi = Distribution(gen);
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

  // Placeholder for the field of the distance vectors
  ndvector<3,double>::t dist_field (
                                     ((nrows-1)*res+1) * ((ncols-1)*res+1),
                                     ndvector<2,double>::t (
                                       4,
                                       ndvector<1,double>::t (2)
                                     )
                                   );
  // Placeholder for the dot product field
  ndvector<2,double>::t dot_grid (
                                    ((nrows-1)*res+1) * ((ncols-1)*res+1),
                                    ndvector<1,double>::t (4)
                                 );

  int sub_i = 0;
  for(auto const& p : std::as_const(_sub_grid))
  {
    auto cc = _get_current_cell(p, nrows, ncols, step);

    int sub_c_i = 0;
    for(auto const &c_i : std::as_const(cc))
    {
      // Current main grid point (which is one of the corners to the current cell)
      auto c = _main_grid[c_i];

      // Placeholder for the current distance vector
      ndvector<1,double>::t d (2);
      // Calculate distance between vectors `c` and `p`: d = c - p
      std::transform(c.begin(), c.end(), p.begin(), d.begin(),
                     std::minus<double>());
      // Add distance vector to the distance vector field
      dist_field[sub_i][sub_c_i] = d;
      
      // Add dot product of distance vector and gradient in corner to the dot field
      auto grad = _gradient_field[c_i];
      dot_grid[sub_i][sub_c_i] = std::inner_product(d.begin(), d.end(), grad.begin(), 0.0);

      sub_c_i++;
    }
    sub_i++;
  }

  _dot_grid = dot_grid;
  _dist_field = dist_field;
}

void
Perlin::set_ngp(int const &nrows, int const &ncols, double const &step, double const &res)
{
  // Placeholder for the indices of the nearest main grid points for every
  // sub grid point
  ndvector<1,int>::t ngp (((nrows-1)*res+1) * ((ncols-1)*res+1));

  // Check whether if this corner is the closest to the sub grid point
  int sub_i = 0;
  for(auto const &d : std::as_const(_dist_field))
  {
    int sub_c_i = 0;
    double ngp_val = step + 1;
    for(auto const &dc : std::as_const(d))
    {
      double dist = sqrt(dc[0]*dc[0] + dc[1]*dc[1]);
      if(dist < ngp_val)
      {
        ngp_val = dist;
        ngp[sub_i] = sub_c_i;
        sub_c_i++;
      }
    }
    sub_i++;
  }

  _ngp = ngp;
}

void
Perlin::set_interp_grid(int const &nrows, int const &ncols, double const &step, double const &res)
{
  ndvector<1,double>::t interp_grid (((ncols-1)*res+1) * ((nrows-1)*res+1));

  int idx = 0;
  for(auto const& dd : std::as_const(_dot_grid))
  {
    // Get the coordinates of the i'th point in the simulation
    auto p = _sub_grid[idx];
    auto cc = _get_current_cell(p, nrows, ncols, step);

    // Determine coordinates of bottom left corner
    double x0 = _main_grid[cc[0]][0];
    double y0 = _main_grid[cc[0]][1];

    // Determine interpolation weights
    // Could also use higher order polynomial/s-curve here
    double sx = p[0] - x0;
    double sy = p[1] - y0;

    auto i_1 = _interpolate(dd[0], dd[1], sx);
    auto i_2 = _interpolate(dd[2], dd[3], sx);

    interp_grid[idx] = _interpolate(i_1, i_2, sy);
    idx++;
  }

  _interp_grid = interp_grid;
}

void
Perlin::set_sub_grad_field(int const &nrows, int const &ncols, double const &res)
{
  // Placeholder for the zero padded gradient field of the sub grid points
  ndvector<2,int>::t pad_grad_field (
                                      ((nrows-1)*res+3) * ((ncols-1)*res+3),
                                      ndvector<1,int>::t (2)
                                    );
  // Placeholder for the zero padded interpolated grod
  ndvector<1,double>::t pad_interp_grid (((ncols-1)*res+3) * ((nrows-1)*res+3), -1);

  // Create the zero padded version of the interpolated grid by inserting the
  // original interpolated grid inside the zero padded one
  for(int i = 1; i < (nrows-1)*res+2; i++)
  {
    for(int j = 1; j < (ncols-1)*res+2; j++)
    {
      int idx = (i-1) * ((ncols-1)*res+1) + (j-1);
      int pidx = i * ((ncols-1)*res+3) + j;
      pad_interp_grid[pidx] = _interp_grid[idx];
    }
  }

  // Determine gradients in the interpolated grid for every sub grid point
  //
  // OH MY GOD PLEASE FORGIVE ME FOR THIS ABOMINATION
  //
  for(int i = 1; i < (nrows-1)*res+2; i++)
  {
    for(int j = 1; j < (ncols-1)*res+2; j++)
    {
      int pidx = i * ((ncols-1)*res+3) + j;
      double p = pad_interp_grid[pidx];
      
      double h_max = 0;
      ndvector<1,int>::t grad (2);
      for(int cy = -1; cy <= 1; cy++)
      {
        for(int cx = -1; cx <= 1; cx++)
        {
          if(cx == 0 && cy == 0)
          {
            continue;
          }
          else
          {
            int cidx = (i+cy) * ((ncols-1)*res+3) + (j+cx);
            double pc = pad_interp_grid[cidx];
            double h = p - pc;
            if(h > h_max)
            {
              h_max = h;
              grad = {cx, cy};
            }
          }
        }
      }
      // Adding gradient to sub gradient field
      pad_grad_field[pidx] = grad;
    }
  }

  // Placeholder for the sub gradient field without zero padding
  ndvector<2,int>::t sub_grad_field (
                                      ((nrows-1)*res+1) * ((ncols-1)*res+1),
                                      ndvector<1,int>::t (2)
                                    );

  // Remove zero padding from the sub gradient field
  for(int i = 1; i < (nrows-1)*res+2; i++)
  {
    for(int j = 1; j < (ncols-1)*res+2; j++)
    {
      int idx = (i-1) * ((ncols-1)*res+1) + (j-1);
      int pidx = i * ((ncols-1)*res+3) + j;
      sub_grad_field[idx] = pad_grad_field[pidx];
      //std::cout << "pidx = " << pidx << std::endl;
      //std::cout << "grads = " << pad_grad_field[pidx][0] << ","
      //                        << pad_grad_field[pidx][1] << std::endl;
    }
  }

  _sub_grad_field = sub_grad_field;
}