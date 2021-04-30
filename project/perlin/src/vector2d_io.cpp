////////////////////////////////////////////////////////
//
//    Creating a custom vector class with operator
//    overloading
//
//    File : overload_io.cpp
//    Desc : Contains definitions to overloading I/O
//           operations for the custom vector class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <vector2d.hpp>

//----------------------------------------//
//  2. Overloading string operators       //
//----------------------------------------//

//  2.a. Print elements of the vector with `<<`
std::ostream& operator<<(std::ostream &o, vector2d const &v)
{
  o << "{ " << v[0] << ", " << v[1] << " }";

  return o;
}

//  2.b. Add elements to vector from input stream with `>>`
std::istream& operator>>(std::istream &i, vector2d &v)
{
  i >> v[0] >> v[1];

  return i;
}