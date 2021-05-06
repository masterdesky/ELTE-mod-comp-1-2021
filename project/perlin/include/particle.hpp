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

class Particle {
  private:
    // X and Y coordinates of the particles
    ndvector<2,double>::t _pos;
    ndvector<2,double>::t _vel;
    ndvector<2,double>::t _acc;

    /* Private methods */
    // Methods to sample uniformly `npart` number of random integers from a set
    // of `all` number integers
    double _pick_value(double const &lim);

  public:
    /* Constructors, destructors */
    Particle() { /* Default constructor */ }

    /* Public methods */
    void set_starting_position(int const &nrows, int const &ncols);

    void trace_particle(Perlin &perlin,
                        int const &nrows, int const &ncols, int const &res,
                        double const &T, double const &dt);
};