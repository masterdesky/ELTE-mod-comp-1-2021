////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : main.cpp
//    Desc : Contains the main method of the project
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

//#include <chrono>
//#include <ctime>

#include <template.hpp>
#include <io.hpp>
#include <flow_field.hpp>
#include <perlin.hpp>
#include <perlin_io.hpp>
#include <particle.hpp>
#include <particle_io.hpp>

int main(int argc, char const *argv[])
{
  if(argc != 8)
  {
    std::cout << "ERROR!\n" << "------" << std::endl;
    std::cout << "NOT ENOUGH ARGUMENTS WERE GIVEN!" << std::endl;
    std::cout << "Usage: ./perlin <nrows> <ncols> <res> <freqs> <npart> <nsteps> <vmax>" << std::endl;
    std::cout << "Exiting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  // Does not check for valid input, please
  // try to give sensible arguments when you're executing it
  int
    nrows = std::stoi(argv[1]),     // Number of horizontal main grid lines   
    ncols = std::stoi(argv[2]),     // Number of vertical main grid lines
    res = std::stoi(argv[3]),       // Number of sub grid lines
    freqs = std::stoi(argv[4]),     // Number of Perlin noises to stack
    npart = std::stoi(argv[5]),     // Number of particles
    nsteps = std::stoi(argv[6]);    // Number of updates

  double
    vmax = std::stoi(argv[7]);      // Maximum velocity of particles


  // Stack Perlin noises to get fractal noise
  ndvector<1,double>::t pool_field;
  ndvector<1,double>::t fractal (res * res);
  for(int i = 0; i < freqs; i++)
  {
    int fr = pow(2, i);
    std::string pfx = std::to_string(fr);

    int nrows_i = nrows * fr;
    int ncols_i = ncols * fr;
    Perlin perlin(nrows_i, ncols_i, res);
    save_perlin(perlin, pfx);

    if(i == 0)
    {
      pool_field = perlin.get_interp_grid();
    }

    // Query the Perlin noise map in this step
    auto interp = perlin.get_interp_grid();
    // Stack it on top of the previous level
    std::transform(fractal.begin(), fractal.end(), interp.begin(), fractal.begin(),
                   std::plus<double>());
  }

  // Run particle simulation
  Particle particle(pool_field, npart, nsteps, res, vmax);
  save_particle(particle);

  return 0;
}