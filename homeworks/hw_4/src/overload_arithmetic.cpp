////////////////////////////////////////////////////////
//
//    Creating a custom vector class with operator
//    overloading
//
//    File : overload_arithmetic.cpp
//    Desc : Contains definitions to overloading arithmetic
//           operations for the custom vector class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <vector.hpp>

//----------------------------------------//
//  1. Overloading arithmetic operators   //
//----------------------------------------//

//  1.a. Overloading arithmetic `+` (addition)
vector2d operator+(vector2d const &v_1, vector2d const &v_2)
{
  return vector2d( v_1[0] + v_2[0],
                   v_1[1] + v_2[1] );
}

vector2d& vector2d::operator+=(vector2d const& v)
{
  vi[0] += v[0];
  vi[1] += v[1];

  // Literally return THIS vector after we've changed the x and y values
  // Note the `&` after the declaration of the return type of this function
  return *this;
}


//  1.b. Overloading arithmetic `-` (subtraction)
vector2d operator-(vector2d const& v_1, vector2d const& v_2)
{
  return vector2d( v_1[0] - v_2[0],
                   v_1[1] - v_2[1] );
}
vector2d& vector2d::operator-=(vector2d const& v)
{
  vi[0] -= v[0];
  vi[0] -= v[1];

  // Literally return THIS vector after we've changed the x and y values
  // Note the `&` after the declaration of the return type of this function
  return *this;
}


//  1.c. Overloading arithmetic `*` (scalar multiplication)
//       from both sides
vector2d operator*(vector2d const &v, double const &c)
{
  return vector2d( v[0] * c,
                   v[1] * c );
}
vector2d operator*(double const &c, vector2d const &v)
{
  return v * c;
}
vector2d& vector2d::operator*=(double const &c)
{
  vi[0] *= c;
  vi[1] *= c;

  // Literally return THIS vector after we've changed the x and y values
  // Note the `&` after the declaration of the return type of this function
  return *this;
}


//  1.d. Overloading arithmetic `/` (scalar division)
vector2d operator/(vector2d const &v, double const &c)
{
  return vector2d( v[0] / c,
                   v[1] / c );
}
vector2d operator/(double const &c, vector2d const &v)
{
  std::cout << "Division of scalar by vector is not allowed!" << std::endl;
  return vector2d ( 0, 0 );
}
vector2d& vector2d::operator/=(double const &c)
{
  vi[0] /= c;
  vi[1] /= c;

  // Literally return THIS vector after we've changed the x and y values
  // Note the `&` after the declaration of the return type of this function
  return *this;
}


// 1.e./i. Subscript operator (non-const)
double& vector2d::operator[](int i)
{
  if( i >= 2 )
  {
    std::cout << "Index out of bounds" << std::endl;
    return vi[0];
  }

  return vi[i];
}

// 1.e./ii. Subscript operator (const)
const double& vector2d::operator[](int i) const
{
  if( i >= 2 )
  {
    std::cout << "Index out of bounds" << std::endl;
    return vi[0];
  }

  return vi[i];
}