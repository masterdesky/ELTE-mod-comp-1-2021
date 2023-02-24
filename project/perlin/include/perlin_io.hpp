////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : perlin_io.hpp
//    Desc : Handles the saving of Perlin classes
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <iostream>

void
save_perlin(Perlin &perlin, std::string prefix)
{
  auto main_grid = perlin.get_main_grid();
  write_to_file (
      main_grid,
      "../data/main_grid_" + prefix + ".dat"
  );

  auto gradient_field = perlin.get_gradient_field();
  write_to_file (
      gradient_field,
      "../data/gradient_field_" + prefix + ".dat"
  );

  auto sub_grid = perlin.get_sub_grid();
  write_to_file (
      sub_grid,
      "../data/sub_grid_" + prefix + ".dat"
  );

  auto cell_corners = perlin.get_cell_corners();
  write_to_file (
      cell_corners,
      "../data/cell_corners_" + prefix + ".dat"
  );

  auto dot_grid = perlin.get_dot_grid();
  write_to_file (
      dot_grid,
      "../data/dot_grid_" + prefix + ".dat"
  );

  auto ngp = perlin.get_ngp();
  write_to_file (
      ngp,
      "../data/ngp_" + prefix + ".dat"
  );

  auto interp_grid = perlin.get_interp_grid();
  write_to_file (
      interp_grid,
      "../data/interp_grid_" + prefix + ".dat"
  );

  auto flow_field = perlin.get_flow_field();
  write_to_file (
      flow_field,
      "../data/flow_field_" + prefix + ".dat"
  );
}