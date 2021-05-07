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

#include <template.hpp>
#include <flow_field.hpp>
#include <particle.hpp>

void
Particle::set_starting_positions(int const &npart, int const &res)
{
  // Placeholder for positions
  ndvector<1,double>::t pos_x(npart), pos_y(npart);
  // Placeholder for velocities (they're 0 at the start)
  ndvector<1,double>::t vel_x(npart), vel_y(npart);
  // Placeholder for accelerations (they're 0 at the start)
  ndvector<1,double>::t acc_x(npart), acc_y(npart);


  for(int n = 0; n < npart; n++)
  {
    pos_x[n] = _pick_value(res-1);
    pos_y[n] = _pick_value(res-1);
  }

  _pos_x.push_back(pos_x); _pos_y.push_back(pos_y);
  _vel_x.push_back(vel_x); _vel_y.push_back(vel_y);
  _acc_x.push_back(acc_x); _acc_y.push_back(acc_y);
}

void
Particle::trace_particles(ndvector<1,double>::t const &fractal,
                          int const &npart, int const &nsteps, int const &res)
{
  // Calculate flow field for the fractal noise
  auto flow_field = calc_flow_field(fractal, res);
  
  int ntaken = 1;
  while(ntaken < nsteps)
  {
    // Placeholder for NEW positions
    ndvector<1,double>::t pos_xn(npart), pos_yn(npart);
    // Placeholder for NEW velocities
    ndvector<1,double>::t vel_xn(npart), vel_yn(npart);
    // Placeholder for NEW accelerations
    ndvector<1,double>::t acc_xn(npart), acc_yn(npart);
    for(int n = 0; n < npart; n++)
    {
      // Get previous positions, velocities and accelerations
      auto pos_x = _pos_x[ntaken-1][n]; auto pos_y = _pos_y[ntaken-1][n];
      auto vel_x = _vel_x[ntaken-1][n]; auto vel_y = _vel_y[ntaken-1][n];
      auto acc_x = _acc_x[ntaken-1][n]; auto acc_y = _acc_y[ntaken-1][n];
      
      int ix = (int)pos_x;
      int iy = (int)pos_y;
      // Get forces acting on the particle
      auto fx = flow_field[iy * res + ix][0];
      auto fy = flow_field[iy * res + ix][1];
      // Apply forces to particles
      acc_xn[n] = fx; acc_yn[n] = fy;

      // Check if velocities are below the allowed maximum
      _speed_check(vel_x, vel_y);

      // Update positions and velocities of particles
      pos_xn[n] = pos_x + vel_x;
      pos_yn[n] = pos_y + vel_y;
      vel_xn[n] = vel_x + acc_xn[n];
      vel_yn[n] = vel_y + acc_yn[n];

      // Apply periodic boundary conditions
      _periodic_boundary(pos_xn[n], pos_yn[n], res);

    }
    // Add new values to the list
    _pos_x.push_back(pos_xn); _pos_y.push_back(pos_yn);
    _vel_x.push_back(vel_xn); _vel_y.push_back(vel_yn);
    _acc_x.push_back(acc_xn); _acc_y.push_back(acc_yn);
    ntaken++;
  }
}