////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : io.hpp
//    Desc : Handles the I/O in the project
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <vector>

template<typename T> void
write_vec(std::vector<T> const &v,
          std::ofstream &output_file)
{
  for (auto const &value:v)
  {
    output_file << value << ',';
  }
}

template<typename T> void
write_vec(std::vector<std::vector<T>> const &v,
          std::ofstream &output_file)
{
  for (auto const &value:v)
  {
    write_vec(value, output_file);
    output_file << '\n';
  }
}

template <typename T> void
write_to_file(T const &table, std::string filename,
              int const &nrows, int const &ncols, double const &res)
{
  std::ofstream output_file;
  // Save the input vector
  output_file.open(filename);
  output_file << nrows << ','
              << ncols << ','
              << res   << std::endl;

  write_vec(table, output_file);

  output_file.close();
}