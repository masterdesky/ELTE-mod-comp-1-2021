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
#include <unordered_set>

#include <template.hpp>
#include <perlin.hpp>
#include <particle.hpp>

std::unordered_set<int>
Particle::_pickSet(int const &all, int const &npart, std::mt19937_64 &gen)
{
  std::unordered_set<int> elems;
  for (int r = all - npart; r < all; r++)
  {
    int v = std::uniform_int_distribution<> (1, r)(gen);

    // there are two cases.
    // v is not in candidates ==> add it
    // v is in candidates ==> well, r is definitely not, because
    // this is the first iteration in the loop that we could've
    // picked something that big.

    if (!elems.insert(v).second)
    {
        elems.insert(r);
    }
  }
  return elems;
}

ndvector<1,int>::t
Particle::_pick(int const &all, int const &npart) {
  std::random_device rd;
  std::mt19937_64 gen(rd());

  std::unordered_set<int> elems = _pickSet(all, npart, gen);

  ndvector<1,int>::t result(elems.begin(), elems.end());
  std::shuffle(result.begin(), result.end(), gen);

  return(result);
}

void
Particle::set_starting_positions(Perlin perlin, int const &npart)
{
  auto sub_grid = perlin.get_sub_grid();
  int all = static_cast<int>(sub_grid.size());

  ndvector<2,int>::t positions (npart);

  auto rdidx = _pick(all, npart);

  int i = 0;
  for(auto const &r : std::as_const(rdidx))
  {
    positions[i].push_back(r);
    i++;
  }
  _positions = positions;
}

void
Particle::trace_particles(Perlin perlin,
                          int const &npart, int const &nrows, int const &ncols, int const &res)
{
  auto sub_cell_corners = perlin.get_sub_cell_corners();
  auto sub_grad_field = perlin.get_sub_grad_field();
  for(int p = 0; p < npart; p++)
  {
    
  }
}