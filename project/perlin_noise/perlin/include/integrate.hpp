////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : integrate.cpp
//    Desc : Contains the integration method for particle
//           flow
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////


#include <iostream>
#include <vector>

//  Simple Euler
void EulerStep(std::vector<double> &x, double tau,
               std::vector<double> derivates(std::vector<double> const&))
{   
    // Time
    // Deflection
    // Velocity
    x += tau * derivates(x);
}

//  Semi-Implicit, Euler-Cromer
void EulerCromerStep(std::vector<double> &x, double tau,
                     std::vector<double> derivates(std::vector<double> const&))
{
    auto x_temp = x;

    // Time
    x_temp[0] += tau * derivates(x)[0];

    // Velocity
    x_temp[2] += tau * derivates(x)[2];

    // Deflection
    x_temp[1] += tau * x_temp[2];

    x = x_temp;
}

//  Fourth order Runge-Kutta
void RK4Step(std::vector<double> const &x, double tau,
             std::vector<double> derivates(std::vector<double> const&))
{
    std::vector<double>
        k1 = tau * derivates(x),
        k2 = tau * derivates(x + 0.5 * k1),
        k3 = tau * derivates(x + 0.5 * k2),
        k4 = tau * derivates(x + k3);

    x += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
}