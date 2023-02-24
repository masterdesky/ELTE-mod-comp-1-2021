////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : particle_io.hpp
//    Desc : Handles the saving of Particle classes
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <iostream>

void
save_particle(Particle &particle)
{
  auto pos_x = particle.get_pos_x();
  write_to_file (
      pos_x,
      "../data/particles/pos_x.dat"
  );
  auto pos_y = particle.get_pos_y();
  write_to_file (
      pos_y,
      "../data/particles/pos_y.dat"
  );

  auto vel_x = particle.get_vel_x();
  write_to_file (
      vel_x,
      "../data/particles/vel_x.dat"
  );
  auto vel_y = particle.get_vel_y();
  write_to_file (
      vel_y,
      "../data/particles/vel_y.dat"
  );

  auto acc_x = particle.get_acc_x();
  write_to_file (
      acc_x,
      "../data/particles/acc_x.dat"
  );
  auto acc_y = particle.get_acc_y();
  write_to_file (
      acc_y,
      "../data/particles/acc_y.dat"
  );
}