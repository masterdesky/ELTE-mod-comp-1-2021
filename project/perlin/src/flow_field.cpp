////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : flow_field.cpp
//    Desc : Calculates the flow field for an input value
//           grid
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <cmath>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>

#include <template.hpp>

ndvector<2,double>::t
calc_flow_field(ndvector<1,double>::t interp_grid, double const &res)
{
  // Placeholder for the flow field
  ndvector<2,double>::t flow_field (res * res);
  // Placeholder for the flow field vector angles
  ndvector<1,double>::t angles (res * res);

  // Calculate the arguments of the flow field's gradient vectors
  double angle_scale = 2.5;
  double mx = 2*pi()*angle_scale;
  std::transform(interp_grid.begin(), interp_grid.end(), angles.begin(),
                 std::bind(std::multiplies<double>(), std::placeholders::_1, mx));


  //   Calculate force vectors   //

  // Placeholder for cos/sin values of the angles and normals
  ndvector<1,double>::t vector_x (res * res, 1), vector_y (res * res, 0);
  ndvector<1,double>::t cos_angles (res * res), sin_angles (res * res);

  // Calculate cos/sin values of angles vector
  int i = 0;
  for (const auto &a:angles)
  {
    cos_angles[i] = cos(a);
    sin_angles[i] = sin(a);
    i++;
  }

  // Placeholders for force vector components
  ndvector<1,double>::t force_x (res * res), force_y (res * res);
  // Calculate force vector components
  ndvector<1,double>::t
    ca_x_vx (res * res), sa_x_vy (res * res),
    sa_x_vx (res * res), ca_x_vy (res * res);

  std::transform(cos_angles.begin(), cos_angles.end(),
                 vector_x.begin(), ca_x_vx.begin(), std::multiplies<double>());
  std::transform(sin_angles.begin(), sin_angles.end(),
                 vector_y.begin(), sa_x_vy.begin(), std::multiplies<double>());
  std::transform(sin_angles.begin(), sin_angles.end(),
                 vector_x.begin(), sa_x_vx.begin(), std::multiplies<double>());
  std::transform(cos_angles.begin(), cos_angles.end(),
                 vector_y.begin(), ca_x_vy.begin(), std::multiplies<double>());

  // Placing the pieces together
  std::transform(ca_x_vx.begin(), ca_x_vx.end(),
                 sa_x_vy.begin(), force_x.begin(), std::minus<double>());
  std::transform(sa_x_vx.begin(), sa_x_vx.end(),
                 ca_x_vy.begin(), force_y.begin(), std::plus<double>());

  for(int i = 0; i < res * res; i++)
  {
    flow_field[i] = { force_x[i], force_y[i] };
  }

  return(flow_field);
}