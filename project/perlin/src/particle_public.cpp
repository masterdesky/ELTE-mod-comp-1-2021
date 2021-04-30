////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : particle_public.cpp
//    Desc : Contains the definition to the public methods
//           of the `Particle` class
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <iostream>
#include <random>
#include <vector>

#include <perlin.hpp>
#include <vector2d.hpp>
#include <particle.hpp>
#include <integrate.hpp>

void
Particle::set_starting_position(int const &nrows, int const &ncols, double const &step)
{
  // Placeholder for positions
  ndvector<2,double>::t positions;
  // Placeholder for velocities (they're 0 at the start)
  ndvector<2,double>::t velocities;

  auto lim_x = ncols * step;
  auto pos_x = _pick_value(lim_x);
  auto lim_y = nrows * step;
  auto pos_y = _pick_value(lim_y);

  ndvector<1,double>::t p = { pos_x, pos_y };
  positions.push_back(p);

  _positions = positions;
  _velocities = velocities;
}

void
Particle::trace_particle(Perlin &perlin,
                         int const &nrows, int const &ncols, double const &step, int const &res,
                         double const &T, double const &dt)
{
  // Basically the force field
  auto interp_field = perlin.get_interp_grid();

  // Starting position
  vector2d p = { _positions[0][0], _positions[0][1] };
  vector2d p_err = { 0., 0. };

  while(p[0] < T)
  {
    // Step the particle simulation
    RK4Step(p, dt, perlin, nrows, ncols, step, res);
    std::cout << "p = " << p << std::endl;
    break;
  }
}