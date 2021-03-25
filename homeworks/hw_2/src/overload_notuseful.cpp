////////////////////////////////////////////////////////
//
//    Creating a custom vector class with operator
//    overloading
//
//    File : overload_notuseful.cpp
//    Desc : Contains definitions to not really useful
//           functions for the custom vector class
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <utility>
#include <vector.hpp>

//----------------------------------------//
//  +1. Adding "useful" methods for class //
//----------------------------------------//

// +1./a. Change vector elements to `69`
vector2d& vector2d::change69()
{
  x = 69;
  y = 69;

  // Literally return THIS vector after we've changed the x and y values
  // Note the `&` after the declaration of the return type of this function
  return *this;
}

// +1./b. Tell whether elements of vector is odd or not
std::pair<bool,bool> vector2d::is_odd()
{
  // First convert elements to integers
  int new_x = (int)x;
  int new_y = (int)y;

  // Then find the last digit of these integers
  int last_x = new_x - 10 * (new_x % 10);
  int last_y = new_y - 10 * (new_y % 10);

  // Create a pair to store bool values
  std::pair<bool,bool> oddity;

  // Check whether first component is odd or not
  if(last_x == 0 || last_x == 2 || last_x == 4 || last_x == 6 || last_x == 8)
  {
    oddity.first = false;
  }
  else if(last_x == 1 || last_x == 3 || last_x == 5 || last_x == 7 || last_x == 9)
  {
    oddity.first = true;
  }
  else
  {
    // Handling errors with this convenient `else` branch
    std::cout << "What happened to the `x` component??" << std::endl;
    return {false, false};
  }

  // Check whether second component is odd or not
  if(last_y == 0 || last_y == 2 || last_y == 4 || last_y == 6 || last_y == 8)
  {
    oddity.second = false;
  }
  else if(last_y == 1 || last_y == 3 || last_y == 5 || last_y == 7 || last_y == 9)
  {
    oddity.second = true;
  }
  else
  {
    // Handling errors with this convenient `else` branch
    std::cout << "What happened to the `y` component??" << std::endl;
    return {false, false};
  }

  return oddity;
}

std::pair<bool,bool> vector2d::is_even()
{
  // Might implement a factory pattern in the next version for easier boolean
  // conversion using only 3 simple classes

  // Return the negation of `is_odd()`
  auto oddity = is_odd();

  // Apply XOR logical operator on elements of the `oddity` pair
  bool first = oddity.first;
  bool second = oddity.second;
  first ^= true;
  second ^= true;

  return {first, second};
}