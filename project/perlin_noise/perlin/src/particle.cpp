////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : particle.cpp
//    Desc : Contains the definition to the public methods
//           of the `Particle` class
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
#include <particle.hpp>
#include <integrate.hpp>

double
Particle::_pick_value(std::mt19937_64 &gen, double const &lim)
{
  return std::uniform_real_distribution<> (0, lim)(gen);
}

ndvector<1,double>::t
Particle::_pick(int const &npart, double const &lim) {
  std::random_device rd;
  std::mt19937_64 gen(rd());

  // Placeholder for the results
  ndvector<1,double>::t result (npart);

  for(int i = 0; i < npart; i++)
  {
    result[i] = _pick_value(gen, lim);
  }

  return result;
}

void
Particle::set_starting_positions(int const &npart,
                                 int const &nrows, int const &ncols, double const &step)
{
  // Placeholder for positions
  ndvector<3,double>::t positions (npart, ndvector<2,double>::t);
  // Placeholder for velocities (they're 0 at the start)
  ndvector<3,double>::t velocities (npart);

  auto lim_x = ncols * step;
  auto pos_x = _pick(npart, lim_x);
  auto lim_y = nrows * step;
  auto pos_y = _pick(npart, lim_y);

  for(int i = 0; i < npart; i++)
  {
    ndvector<1,double>::t p = { pos_x[i], pos_y[i] };
    positions[i].push_back(p);
  }
  _positions = positions;
  _velocities = velocities;
}

void
Particle::trace_particles(Perlin &perlin, int const &npart,
                          int const &nrows, int const &ncols, int const &res,
                          double const &T, double const &dt)
{
  auto sub_cell_corners = perlin.get_sub_cell_corners();
  auto sub_grad_field = perlin.get_sub_grad_field();
  for(int p = 0; p < npart; p++)
  {
    continue;
  }
}