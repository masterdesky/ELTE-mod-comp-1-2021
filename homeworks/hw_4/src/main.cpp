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
    std::cout << "Usage: ./integrate <dx> <x_max> <e/r/rk/rkf>" << std::endl;
    std::cout << "Exiting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  double dx = std::stod(argv[1]);
  double x_max = std::stod(argv[2]);
  std::string intg = argv[3];

  // Starting condition (i = 0)
  vector2d Y = { 0., 0. };
  std::cout << Y << std::endl;
  
  // Iteration start (i = 1)
  do
  {
    if(intg == "e") { EulerStep(Y, dx, f_prime); }
    else if(intg == "r") { RK4Step(Y, dx, f_prime); }
    else if(intg == "rk") { RKCKStep(Y, dx, f_prime); }
    else if(intg == "rkf") { RKFStep(Y, dx, f_prime); }
    else { std::cout << "get fucked" << std::endl; break; }
    std::cout << Y << std::endl;
  } while(Y[0] < x_max);

  return 0;
}