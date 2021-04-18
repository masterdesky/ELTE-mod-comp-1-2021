////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : particle.hpp
//    Desc : Contains the declaration to the `Particle` class
//           that handles the particle movement
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <random>
#include <unordered_set>

class Particle {
  private:
    // X and Y coordinates of the particles
    ndvector<2,double>::t _positions_x;
    ndvector<2,double>::t _positions_y;

    /* Private methods */
    // Methods to sample uniformly `npart` number of random integers from a set
    // of `all` number integers
    std::unordered_set<int> _pickSet(int const &allpoint, int const &npart, std::mt19937_64 &gen);
    ndvector<1,int>::t _pick(int const &allpoint, int const &npart);

  public:
    /* Constructors, destructors */
    Particle() { /* Default constructor */ }

    /* Public methods */
    void set_starting_positions(Perlin perlin, int const &npart);

    void trace_particles(Perlin perlin, int const &npart, int const &nrows, int const &ncols, int const &res);
};