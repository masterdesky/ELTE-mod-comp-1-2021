#include <iostream>
#include <fstream>

#include <math.h>
#include <vector>
#include <chrono>
#include <ctime>

#include <template.h>
#include <generate_grid.h>

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		std::cout << "ERROR!\n" << "------" << std::endl;
		std::cout << "NOT ENOUGH ARGUMENTS WERE GIVEN!" << std::endl;
		std::cout << "Usage: ./generate_perlin_noise <nrows> <ncols> <res>" << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(EXIT_FAILURE);
	}

	// Currently does not check for valid input, please
	// try to give sensible arguments when execute
	int nrows = std::stoi(argv[1]);
	int ncols = std::stoi(argv[2]);

	// Resolution of sub-cells
	// A regular cell consists of 4 sub-cells with `res`x`res` number of points each
	int res = std::stoi(argv[3]);

	// Create the coordinate grid
	auto coordinates = get_coordinates(nrows, ncols,
																		 {0, (double)ncols}, {0, (double)nrows});
	write_to_file<vec_2d<double>>(coordinates,
																"../data/coordinates.txt");

	// Mark cell borders
	auto cells = create_cells(nrows, ncols);
	write_to_file<vec_2d<int>>(cells,
										 				 "../data/cells.txt");

	// Create smaller square sub-grids inside cells
	auto sub_grid = create_sub_grid(res,
																	coordinates, cells);
	//write_to_file<std::vector<double>>(sub_grid,
	//											"sub_grid.txt");

	// Create the initial gradient field
	auto gradient_field = get_gradient_field(nrows, ncols);
	write_to_file<vec_2d<double>>(gradient_field,
																"../data/gradient_field.txt");

	// Calculate the distance vectors for sub-cells
	auto dist_vector_field = get_dist_vector_field(res,
																										 coordinates, cells);

	// Calculate the dot products for all the sub-cell coordinates

	return(0);
}