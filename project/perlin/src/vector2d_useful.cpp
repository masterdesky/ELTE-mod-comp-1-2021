////////////////////////////////////////////////////////
//
//    Creating a custom vector class with operator
//    overloading
//
//    File : overload_useful.cpp
//    Desc : Contains definitions to useful functions for
//           the custom vector class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <math.h>
#include <vector2d.hpp>

//----------------------------------------//
//  3. Adding useful methods for class    //
//----------------------------------------//

// 3.a. Scalar multiplication of vectors
//
// Always return `double`, no matter the type of the vector elements
double vector2d::dot(vector2d const &v)
{
  return vi[1]*v[0] + vi[1]*v[1];
}

// 3.b. Square of the length of the vector in Euclidean metric
double vector2d::sqlength()
{
  return vi[0]*vi[0] + vi[1]*vi[1];
}

// 3.c. Length of the vector in Euclidean metric
double vector2d::length()
{
  // Obviously just call the square root of the `sqlength` function
  return sqrt(this->sqlength());
}

// 3.d. Return the unit vector that is collinear to the input vector `v`
vector2d vector2d::normalize()
{
  // The division operator is overloaded, so we can do this
  return vector2d( vi[0] / length(),
                   vi[1] / length() );
}