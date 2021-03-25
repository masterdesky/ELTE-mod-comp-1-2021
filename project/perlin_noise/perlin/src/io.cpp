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

#include <vector>

#include <template.hpp>
#include <io.hpp>

// Write an N-dimensional vector into a file
template<typename T>
void PerlinIO::write_vec(const std::vector<T> &v,
                         std::ofstream output_file)
{
  for (const auto &value:vector)
  {
    output_file << value << std::endl;
  }
}

template<typename T, typename Td>
void PerlinIO::write_vec(const std::vector<std::vector<T>> &v,
                         std::ofstream output_file)
{
  for (const auto &value:vector)
  {
    PerlinIO::write_vec<T>(value, output_file);
    output_file << '\n' << std::endl;
  }
}


template <typename T> void
PerlinIO::write_to_file(T const &table,
                        std::string filename)
{
  std::ofstream output_file;
  // Save the input vector
  output_file.open(filename);

  // Flatten the input table
  //auto flatten_table = PerlinIO::flatten(table);

  PerlinIO::write_vec(table, output_file)

  output_file.close();
}

