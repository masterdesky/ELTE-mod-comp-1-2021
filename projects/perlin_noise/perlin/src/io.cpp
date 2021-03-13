////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : io.cpp
//    Desc : Handles the I/O in the project
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

#include <template.hpp>
#include <io.hpp>

// Write an N-dimensional vector into a file
template <typename T>
void PerlinIO::write_to_file(T const &table,
                             std::string filename)
{
  std::ofstream output_file;
  // Save the input vector
  output_file.open(filename);

  // Flatten the input table
  auto flatten_table = PerlinIO::flatten(table);

  for(std::size_t i = 0; i < table.size(); i++)
  {
    for(std::size_t j = 0; j < table[i].size(); j++)
    {
      output_file << table[i][j] << ",";
    }
    output_file << std::endl;
  }

  output_file.close();
}

ndvector<1,double>::t
PerlinIO::flatten(T const &table)
{
  ndvector<1,double>::t flatten_table;

  return flatten_table;
}

