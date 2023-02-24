////////////////////////////////////////////////////////
//
//    Creating a custom vector class with operator
//    overloading
//
//    File : vector.hpp
//    Desc : Contains the declaration of the custom
//           vector class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <utility>

class vector2d
{
  /*
  Implements an R^2 vector class, with appropriate operator overloading for
  arithmetic and string operation and more.

  Elements of the vector are always stored as double precision variables. The
  reason for this is that properly handling type conversion in case of scalar
  multiplication or division for any usecases, requires much more work than I'm
  willing to invest in it. Sorry Balázs.
  */

  public:
    // Storing elements of the R^2 vector
    double x, y;

    //----------------------------------------//
    //  0. Constructor for the vector class   //
    //----------------------------------------//
    vector2d() {}
    vector2d(double x_i, double y_i)
    {
      x = x_i;
      y = y_i;
    }

    //----------------------------------------//
    //  1. Overloading arithmetic operators   //
    //----------------------------------------//

    //  1.a. Overloading arithmetic `+` and `+=` (addition)
    friend vector2d operator+(vector2d const& v_1, vector2d const& v_2);
    vector2d& operator+=(vector2d const& v);

    //  1.b. Overloading arithmetic `-` and `-=` (subtraction)
    friend vector2d operator-(vector2d const& v_1, vector2d const& v_2);
    vector2d& operator-=(vector2d const& v);

    //  1.c. Overloading arithmetic `*` and `*=` (scalar multiplication)
    //       from both sides
    friend vector2d operator*(vector2d const& v, double const& c);
    friend vector2d operator*(double const& c, vector2d const& v);
    vector2d& operator*=(double const& c);

    //  1.d. Overloading arithmetic `/` and `/=` (scalar division)
    friend vector2d operator/(vector2d const& v, double const& c);
    friend vector2d operator/(double const& c, vector2d const& v);
    vector2d& operator/=(double const& c);


    //----------------------------------------//
    //  2. Overloading string operators       //
    //----------------------------------------//

    //  2.a. Print elements of the vector with `<<`
    friend std::ostream& operator<<(std::ostream& o, vector2d const& v);

    //  2.b. Add elements to vector from input stream with `>>`
    friend std::istream& operator>>(std::istream& i, vector2d& v);


    //----------------------------------------//
    //  3. Adding useful methods for class    //
    //----------------------------------------//

    // 3.a. Scalar multiplication of vectors
    //
    // Always return `double`, no matter the type of the vector elements
    double dot(vector2d const& v);

    // 3.b. Square of the length of the vector in Euclidean metric
    double sqlength();

    // 3.c. Length of the vector in Euclidean metric
    double length();

    // 3.d. Return the unit vector that is collinear vector
    vector2d normalize();

    //----------------------------------------//
    //  +1. Adding "useful" methods for class //
    //----------------------------------------//

    // +1./a. Change vector elements to `69`
    vector2d& change69();

    // +1./b. Tell whether elements of vector is odd or not
    std::pair<bool,bool> is_odd();

    std::pair<bool,bool> is_even();
};