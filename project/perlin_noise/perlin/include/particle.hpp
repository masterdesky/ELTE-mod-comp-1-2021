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

class Particle {
  private:
    // X and Y coordinates of the particles
    ndvector<2,double>::t _positions;
    ndvector<2,double>::t _velocities;

    /* Private methods */
    // Methods to sample uniformly `npart` number of random integers from a set
    // of `all` number integers
    double _pick_value(std::mt19937_64 &gen, double const &lim);
    ndvector<1,double>::t _pick(int const &npart, double const &lim);

  public:
    /* Constructors, destructors */
    Particle() { /* Default constructor */ }

    /* Public methods */
    void set_starting_positions(int const &npart,
                                int const &nrows, int const &ncols, double const &step);

    void trace_particles(Perlin &perlin, int const &npart,
                         int const &nrows, int const &ncols, int const &res,
                         double const &T, double const &dt);
};