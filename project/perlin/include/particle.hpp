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
    ndvector<2,double>::t _pos_x, _pos_y;
    ndvector<2,double>::t _vel_x, _vel_y;
    ndvector<2,double>::t _acc_x, _acc_y;

    double _v_max;

    /* Private methods */
    // Methods to sample uniformly `npart` number of random integers from a set
    // of `all` number integers
    double _pick_value(double const &lim);

    void _speed_check(double &vel_x, double &vel_y);

    void _periodic_boundary(double &pos_x, double &pos_y, int const &res);

  public:
    /* Constructors, destructors */
    Particle() { /* Default constructor */ }
    Particle(ndvector<1,double>::t const &fractal,
             int const &npart,
             int const &nsteps,
             int const &res,
             double const &v_max)
    {
        _v_max = v_max;
        set_starting_positions(npart, res);
        trace_particles(fractal, npart, nsteps, res);
    }

    /* Collect positions, velocities and accelerations */
    ndvector<2,double>::t get_pos_x() { return _pos_x; }
    ndvector<2,double>::t get_pos_y() { return _pos_y; }
    ndvector<2,double>::t get_vel_x() { return _vel_x; }
    ndvector<2,double>::t get_vel_y() { return _vel_y; }
    ndvector<2,double>::t get_acc_x() { return _acc_x; }
    ndvector<2,double>::t get_acc_y() { return _acc_y; }

    /* Public methods */
    void set_starting_positions(int const &npart, int const &res);

    void trace_particles(ndvector<1,double>::t const &fractal,
                         int const &npart, int const &nsteps, int const &res);
};