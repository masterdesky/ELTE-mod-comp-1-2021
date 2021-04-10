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

template<typename T> void
write_vec(std::vector<T> const &v,
          std::ofstream output_file)
{
  for (auto const &value:v)
  {
    output_file << value << std::endl;
  }
}

template<typename T> void
write_vec(std::vector<std::vector<T>> const &v,
          std::ofstream output_file)
{
  for (auto const &value:v)
  {
    write_vec<T>(value, output_file);
    output_file << '\n' << std::endl;
  }
}

template <typename T> void
write_to_file(T const &table,
              std::string filename)
{
  std::ofstream output_file;
  // Save the input vector
  output_file.open(filename);

  write_vec<T>(table, output_file);

  output_file.close();
}