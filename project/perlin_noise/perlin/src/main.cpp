////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : main.cpp
//    Desc : Contains the main method of the project
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

#include <math.h>
#include <vector>
#include <chrono>
#include <ctime>

#include <template.hpp>
#include <perlin.hpp>
#include <io.hpp>

int main(int argc, char const *argv[])
{
	if(argc != 5)
	{
		std::cout << "ERROR!\n" << "------" << std::endl;
		std::cout << "NOT ENOUGH ARGUMENTS WERE GIVEN!" << std::endl;
		std::cout << "Usage: ./perlin <nrows> <ncols> <step> <res>" << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(EXIT_FAILURE);
	}

	// Currently does not check for valid input, please
	// try to give sensible arguments when execute
	int nrows = std::stoi(argv[1]);
	int ncols = std::stoi(argv[2]);
	// Size between two neighbouring grid points in any directions
	double step = std::stoi(argv[3]);
	// Resolution of sub-cells
	// A regular cell consists of 4 sub-cells with `res`x`res` number of points
	int res = std::stoi(argv[4]);

	////////////////////////////////////////////////////////
	//
	//  I. Create the outer, main grid
	//
	////
	Perlin perlin_1;
	perlin_1.set_main_grid (nrows, ncols, step);
	perlin_1.set_gradient_field (nrows, ncols);

	auto main_grid = perlin_1.get_main_grid();
	/*write_to_file<ndvector<2,double>::t> (
			main_grid,
			"../data/main_grid.dat"
	);*/

	/*
	// Mark main cell borders
	auto cells = Perlin::create_cells(nrows, ncols);
	PerlinIO::write_to_file<ndvector<2,int>::t>(
			cells,
			"../data/cells.dat"
	);

	////////////////////////////////////////////////////////
	//
	//  II. Create the inner, high resolution sub-grid
	//
	////
	auto grid_sub = Perlin::create_sub_grid(
											res,
											grid_main, cells
									);
	//write_to_file<std::vector<double>>(sub_grid,
	//											"sub_grid.dat");

	////////////////////////////////////////////////////////
	//
	//  III. Create the initial gradient field
	//
	////
	auto gradient_field = Perlin::get_gradient_field(
														nrows, ncols
												);
	PerlinIO::write_to_file<ndvector<2,double>::t>(
			gradient_field,
			"../data/gradient_field.txt"
	);

	// Calculate the distance vectors for sub-cells
	auto dist_vector_field = Perlin::get_dist_vector_field(
													 		res,
													 		grid_main, cells
													 );

	////////////////////////////////////////////////////////
	//
	//  IV. Calculate the dot products for all the
	//      sub-cell coordinates
	//
	////


	////////////////////////////////////////////////////////
	//
	//	V. 
	//
	////
	*/
	return 0;
}