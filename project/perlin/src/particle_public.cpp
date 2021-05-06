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
#include <particle.hpp>

void
Particle::set_starting_position(int const &nrows, int const &ncols)
{
  // Placeholder for positions
  ndvector<2,double>::t pos;
  // Placeholder for velocities (they're 0 at the start)
  ndvector<2,double>::t vel;
  // Placeholder for accelerations (they're 0 at the start)
  ndvector<2,double>::t acc;

  auto pos_x = _pick_value(ncols);
  auto pos_y = _pick_value(nrows);

  ndvector<1,double>::t p = { pos_x, pos_y };
  ndvector<1,double>::t v = { 0., 0. };
  ndvector<1,double>::t a = { 0., 0. };
  pos.push_back(p);
  vel.push_back(v);
  acc.push_back(a);

  _pos = pos;
  _vel = vel;
  _acc = acc;
}

void
Particle::trace_particle(Perlin &perlin,
                         int const &nrows, int const &ncols, int const &res,
                         double const &T, double const &dt)
{
  // Basically the force field
  auto interp_field = perlin.get_interp_grid();

  // Starting coordinates
  ndvector<1,double>::t p = { 0, _pos[0][0], _pos[0][1] };

  while(p[0] < T)
  {
    break;
  }
}