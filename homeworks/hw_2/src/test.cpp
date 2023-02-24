////////////////////////////////////////////////////////
//
//    Creating a custom vector class with operator
//    overloading
//
//    File : test.cpp
//    Desc : Contains the test cases for the vector
//           class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <vector.hpp>


void test_arithmetic_add_sub(vector2d& v_1, vector2d& v_2)
{
  // Testing arithmetic `+` operator
  std::cout << "TEST #01 : arithmetic `+` operator"         << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", v_2 = " << v_2  << std::endl;
  std::cout << v_1 << " + " << v_2 << " = " << v_1+v_2      << std::endl;

  std::cout << '\n' << std::endl;

  // Testing arithmetic `+=` operator
  std::cout << "TEST #02 : arithmetic `+=` operator"        << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", v_2 = " << v_2  << std::endl;
  std::cout << "Calculating v_1 += v_2... "                 << std::endl;
  v_1 += v_2;
  std::cout << "Now the value of v_1 = " << v_1             << std::endl;

  std::cout << '\n' << std::endl;

  // Testing arithmetic `-` operator
  std::cout << "TEST #03 : arithmetic `-` operator"         << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", v_2 = " << v_2  << std::endl;
  std::cout << v_1 << " - " << v_2 << " = " << v_1-v_2      << std::endl;

  std::cout << '\n' << std::endl;

  // Testing arithmetic `+=` operator
  std::cout << "TEST #04 : arithmetic `-=` operator"        << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", v_2 = " << v_2  << std::endl;
  std::cout << "Calculating v_1 -= v_2... "                 << std::endl;
  v_1 -= v_2;
  std::cout << "Now the value of v_1 = " << v_1             << std::endl;

  std::cout << '\n' << std::endl;
}


void test_arithmetic_mul_div(vector2d &v_1, double &c)
{
  // Testing arithmetic `+` operator
  std::cout << "TEST #05 : arithmetic `*` operator"         << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", c = " << c      << std::endl;
  std::cout << v_1 << " * " << c << " = " << v_1*c          << std::endl;

  std::cout << '\n' << std::endl;

  // Testing arithmetic `+=` operator
  std::cout << "TEST #06 : arithmetic `*=` operator"        << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", c = " << c      << std::endl;
  std::cout << "Calculating v_1 *= c... "                   << std::endl;
  v_1 *= c;
  std::cout << "Now the value of v_1 = " << v_1             << std::endl;

  std::cout << '\n' << std::endl;

  // Testing arithmetic `-` operator
  std::cout << "TEST #07 : arithmetic `/` operator"         << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", c = " << c      << std::endl;
  std::cout << v_1 << " / " << c << " = " << v_1/c          << std::endl;

  std::cout << '\n' << std::endl;

  // Testing arithmetic `/=` operator
  std::cout << "TEST #08 : arithmetic `/=` operator"        << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", c = " << c      << std::endl;
  std::cout << "Calculating v_1 /= c... "                   << std::endl;
  v_1 /= c;
  std::cout << "Now the value of v_1 = " << v_1             << std::endl;

  std::cout << '\n' << std::endl;
}

void test_useful_functions(vector2d& v_1, vector2d& v_2)
{
  std::cout << "TEST #09 : Dot product of input vectors"    << std::endl;
  std::cout << "Input: v_1 = " << v_1 << ", v_2 = " << v_2  << std::endl;
  std::cout << v_1 << " * " << v_2 << " = " << v_1.dot(v_2) << std::endl;
  std::cout << v_2 << " * " << v_1 << " = " << v_2.dot(v_1) << std::endl;

  std::cout << '\n' << std::endl;

  std::cout << "TEST #10 : Length of input vectors"         << std::endl;
  std::cout << "|" << v_1 << "| = " << v_1.length()         << std::endl;
  std::cout << "|" << v_2 << "| = " << v_2.length()         << std::endl;

  std::cout << '\n' << std::endl;

  std::cout << "TEST #11 : Square length of input vectors"  << std::endl;
  std::cout << "|" << v_1 << "|^2 = " << v_1.sqlength()     << std::endl;
  std::cout << "|" << v_2 <<"|^2 = " << v_2.sqlength()      << std::endl;

  std::cout << '\n' << std::endl;

  std::cout << "TEST #12 : Appropriate unit vectors of input vectors"
            << std::endl;
  std::cout << "|" << v_1 << "|^2 = " << v_1.normalize()    << std::endl;
  std::cout << "|" << v_2 << "|^2 = " << v_2.normalize()    << std::endl;

  std::cout << '\n' << std::endl;
}