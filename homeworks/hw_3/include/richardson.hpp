////////////////////////////////////////////////////////
//
//    Numerical integration
//
//    File : richardson.hpp
//    Desc : Contains the Richardson methods
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

double
R_2(String &s, double const &x, double const &h)
{
    return (s.f(x+h) - s.f(x-h)) / (2*h);
}

double
R_4(String &s, double const &x, double const &h)
{
    return (4*R_2(s, x, h) - R_2(s, x, 2*h)) / 3;
}

double
R_6(String &s, double const &x, double const &h)
{
    return (16*R_4(s, x, h) - R_4(s, x, 2*h)) / 15;
}