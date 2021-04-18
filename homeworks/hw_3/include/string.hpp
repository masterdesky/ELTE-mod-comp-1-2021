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
    double h;

    double _get_value(double const &x);

  public:
    /* Constructors and deconstructors */
    //String() { /* Default constructor */ }
    String(double const &Fi, double const &qi, double const &ai, double const &hi)
    : F(Fi), q(qi), a(ai), h(hi)
    {}

    ~String() { std::cout << "String destructor called" << std::endl; }

    std::vector<double> sample(std::vector<double> const &X);

};