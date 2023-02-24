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
#include <functional>

#include <string.hpp>
#include <vector.hpp>
#include <integrate.hpp>

int main(int argc, char const *argv[])
{
  if(argc != 7)
  {
    std::cout << "ERROR!\n" << "------" << std::endl;
    std::cout << "NOT ENOUGH ARGUMENTS WERE GIVEN!" << std::endl;
    std::cout << "Usage: ./integrate <F> <q> <a> <b> <h> <N>" << std::endl;
    std::cout << "Exiting..." << std::endl;
    exit(EXIT_FAILURE);
  }

  // Read in parameters
  double F = std::stod(argv[1]);
  double q = std::stod(argv[2]);
  double a = std::stod(argv[3]);
  double b = std::stod(argv[4]);
  double h = std::stod(argv[5]);
  int N = std::stoi(argv[6]);

  String string(F,q,a,b,h,N);
  auto fp = std::bind(&String::dL, string, std::placeholders::_1);

  double L;
  // Length with rectangle method
  L = rectangle(fp, N, a, b);
  std::cout << "Length with rectangle method = " << L << std::endl;

  // Length with trapezoid method
  L = trapezoid(fp, N, a, b);
  std::cout << "Length with trapezoid method = " << L << std::endl;

  // Length with 1/3 Simpson method
  L = Simpson(fp, N, a, b);
  std::cout << "Length with 1/3 Simpson method = " << L << std::endl;

  return 0;
}