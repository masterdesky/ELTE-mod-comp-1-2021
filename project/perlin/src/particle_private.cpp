////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : particle_private.cpp
//    Desc : Contains the definition to the private methods
//           of the `Particle` class
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <random>

#include <template.hpp>
#include <particle.hpp>

double
Particle::_pick_value(double const &lim)
{
  std::random_device rd;
  std::mt19937_64 gen(rd());

  return std::uniform_real_distribution<> (0, lim)(gen);
}

void
Particle::_speed_check(double &vel_x, double &vel_y)
{
  double v_norm = sqrt(vel_x*vel_x + vel_y*vel_y);
  if(v_norm > _v_max)
  {
    vel_x /= v_norm;
    vel_y /= v_norm;
  }
}

void
Particle::_periodic_boundary(double &pos_x, double &pos_y, int const &res)
{
  // Check if the ith particle has moved past the left edge of the
  // grid. If so, then map it to the right edge of the grid.
  if (pos_x < 0) { pos_x = res - 1; }

  // Check if the ith particle has moved past the right edge of the
  // grid. If so, then map it to the left edge of the grid.
  if (pos_x > res - 1) { pos_x = 0; }

  // Check if the ith particle has moved past the bottom edge of the
  // grid. If so, then map it to the top edge of the grid.
  if (pos_y < 0) { pos_y = res - 1; }

  // Check if the ith particle has moved past the top edge of the
  // grid. If so, then map it to the bottom edge of the grid.
  if (pos_y > res - 1) { pos_y = 0; }
}