////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : flow_field.hpp
//    Desc : Calculates the flow field for an input value
//           grid
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

ndvector<2,double>::t
calc_flow_field(ndvector<1,double>::t interp_grid, double const &res);