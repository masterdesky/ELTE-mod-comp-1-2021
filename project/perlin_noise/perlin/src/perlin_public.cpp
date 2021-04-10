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
  std::random_device Randomized;
  std::mt19937_64 Generate(Randomized());
  std::uniform_real_distribution<> Distribution(0, 2*pi());

  // Placeholder for the gradient field
  ndvector<2,double>::t gradient_field (nrows * ncols);

  // Generate the gradient field
  for(int i = 0; i < nrows; i++)
  {
    for(int j = 0; j < ncols; j++)
    {
      double phi = Distribution(Generate);
      gradient_field[i * ncols + j] = _get_gradient(phi);
    }
  }

  _gradient_field = gradient_field;
}