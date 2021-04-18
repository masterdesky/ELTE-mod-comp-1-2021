////////////////////////////////////////////////////////
//
//    Numerical integration
//
//    File : string.hpp
//    Desc : Contains declaration to the `String` class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <vector>

class String {

  private:
    double F;
    double q;
    double a;
    double b;
    double h;
    int N;

  public:
    /* Constructors and deconstructors */
    //String() { /* Default constructor */ }
    String(double const &Fi, double const &qi, double const &ai,
           double const &bi, double const &hi, int const &n)
    : F(Fi), q(qi), a(ai), b(bi), h(hi), N(n)
    {}

    //~String() { std::cout << "String destructor called" << std::endl; }

    // The value of the curve at a specific point
    double f(double const &x);

    // The value of the derivative of the curve at a specific point
    double fprime(double const &x);

    // The length of the unit line segment on the curve
    double dL(double const &x);

};