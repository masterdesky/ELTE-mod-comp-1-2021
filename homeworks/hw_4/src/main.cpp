////////////////////////////////////////////////////////
//
//    Numerical integration
//
//    File : main.cpp
//    Desc : Contains the main function of the project
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <vector>

#include <vector.hpp>
#include <integrate.hpp>

vector2d f_prime(vector2d const& x)
{
  return { 1, 1 + x[1]*x[1] };
}

int main(int argc, char const *argv[])
{
  if(argc != 4)
  {
    std::cout << "ERROR!\n" << "------" << std::endl;
    std::cout << "NOT ENOUGH ARGUMENTS WERE GIVEN!" << std::endl;
    std::cout << "Usage: ./integrate <dx> <x_max> <a/e/r/rk/rkf>" << std::endl;
    std::cout << "Exiting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  double dx = std::stod(argv[1]);
  double x_max = std::stod(argv[2]);
  std::string intg = argv[3];

  // Starting condition (i = 0)
  vector2d Y = { 0., 0. };
  vector2d Y_err = { 0., 0. };
  std::cout << Y << " +- " << Y_err << std::endl;
  
  // Iteration start (i = 1)
  while(Y[0] < x_max)
  {
    if(intg == "a") { AnalyticStep(Y, dx); }
    else if(intg == "e") { EulerStep(Y, dx, f_prime); }
    else if(intg == "r") { RK4Step(Y, dx, f_prime); }
    else if(intg == "rk") { RKCKStep(Y, dx, f_prime, Y_err); }
    else if(intg == "rkf") { RKFStep(Y, dx, f_prime, Y_err); }
    else { std::cout << "Please use 'a', 'r', 'e', 'rk' or 'rkf' as third argument!"
                     << std::endl; break; }
    std::cout << Y << " +- " << Y_err << std::endl;
  }

  return 0;
}