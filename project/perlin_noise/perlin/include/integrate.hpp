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


// Take a single Euler step
extern void EulerStep(
  vector2d &x,                             //  extended solution vector
  double dx,                               //  step size
  vector2d derivates(vector2d const &x)    //  extended derivative vector
);

// Take a single 4th order Runge-Kutta step
extern void RK4Step(
  vector2d &x,                             //  extended solution vector
  double dx,                               //  step size
  vector2d derivates(vector2d const &x)    //  extended derivative vector
);

// Take a single Runge-Kutta-Cash-Karp step
extern void RKCKStep(
  vector2d &x,                             //  extended solution vector
  double dx,                               //  step size
  vector2d derivates(vector2d const &x),   //  extended derivative vector
  vector2d &x_err                          //  error of the fit
);

// Take a single 4(5) Runge-Kutta-Fehlberg step
extern void RKFStep(
  vector2d &x,                             //  extended solution vector
  double dx,                               //  step size
  vector2d derivates(vector2d const &x),   //  extended derivative vector
  vector2d &x_err                          //  error of the fit
);