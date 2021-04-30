////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : integrate.cpp
//    Desc : Contains the definition to the integration
//           methods used for particle simulation
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <iostream>

#include <vector2d.hpp>
#include <perlin.hpp>
#include <integrate.hpp>

//
//  Gradient calculation
//
vector2d
derivates(vector2d const &p, Perlin &perlin,
          int const &nrows, int const &ncols, double const &step, int const &res)
{
  // Calculate the force gradient from the interpolated values in the
  // corners of the current sub grid cell
  ndvector<1,double>::t ptmp = { p[0], p[1] };
  auto cc = perlin.get_current_sub_cell(ptmp, nrows, ncols, step, res);
  auto sg = perlin.get_sub_grid();
  auto ig = perlin.get_interp_grid();

  vector2d grad = { 0., 0. };
  vector2d dist = { 1., 1. };
  for(auto const &c_i : std::as_const(cc))
  {
    // Current sub grid point (which is one of the corners to the current cell)
    auto ctmp = sg[c_i];
    vector2d c = { ctmp[0], ctmp[1] };

    // Calculate inverse distance between vectors `c` and `p`: d = c - p
    auto d = dist - (c - p);
    
    // Calculate contribution of corner to gradient
    grad += ig[c_i] * d;
  }

  return grad;
}


// Fourth order Runge-Kutta
void RK4Step(vector2d &x,
             double const &dx,
             Perlin &perlin,
             int const &nrows, int const &ncols, double const &step, int const &res)
{
  vector2d
    k1 = dx * derivates(x, perlin, nrows, ncols, step, res),
    k2 = dx * derivates(x + 0.5 * k1, perlin, nrows, ncols, step, res),
    k3 = dx * derivates(x + 0.5 * k2, perlin, nrows, ncols, step, res),
    k4 = dx * derivates(x + k3, perlin, nrows, ncols, step, res);

  x += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
}