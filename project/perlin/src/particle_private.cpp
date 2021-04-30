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

#include <perlin.hpp>
#include <particle.hpp>

double
Particle::_pick_value(double const &lim)
{
  std::random_device rd;
  std::mt19937_64 gen(rd());

  return std::uniform_real_distribution<> (0, lim)(gen);
}