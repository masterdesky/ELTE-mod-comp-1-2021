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

#include <string.hpp>
#include <integrate.hpp>

int main(int argc, char const *argv[])
{
  if(argc != 6)
  {
    std::cout << "ERROR!\n" << "------" << std::endl;
    std::cout << "NOT ENOUGH ARGUMENTS WERE GIVEN!" << std::endl;
    std::cout << "Usage: ./integrate <F> <q> <a> <h> <N>" << std::endl;
    std::cout << "Exiting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  // Read in parameters
  double F = std::stod(argv[1]);
  double q = std::stod(argv[2]);
  double a = std::stod(argv[3]);
  double h = std::stod(argv[4]);
  int N = std::stoi(argv[5]);

  String string(F,q,a,h);
  auto A = rectangle(string, N, a);
  std::cout << "Area with rectangle method = " << A << std::endl;

  return 0;
}