////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : integrate.hpp
//    Desc : Contains the declarations to the integration
//           methods used for particle simulation
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

vector2d derivates(vector2d const &p, Perlin &perlin,
                   int const &nrows, int const &ncols, double const &step, int const &res);

// Take a single 4th order Runge-Kutta step
void RK4Step(
  vector2d &x,            //  extended solution vector
  double const &dx,       //  step size
  Perlin &perlin,
  int const &nrows, int const &ncols, double const &step, int const &res
);