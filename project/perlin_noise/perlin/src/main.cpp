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
#include <perlin_io.hpp>
#include <particle.hpp>

int main(int argc, char const *argv[])
{
	if(argc != 4)
	{
		std::cout << "ERROR!\n" << "------" << std::endl;
		std::cout << "NOT ENOUGH ARGUMENTS WERE GIVEN!" << std::endl;
		std::cout << "Usage: ./perlin <nrows> <ncols> <res>" << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(EXIT_FAILURE);
	}

	// Currently does not check for valid input, please
	// try to give sensible arguments when execute
	int nrows_0 = std::stoi(argv[1]);
	int ncols_0 = std::stoi(argv[2]);
	// Size between two neighbouring grid points in any directions
	double step_0 = 1.0;
	// Resolution of sub-cells
	// A regular cell consists of 4 sub-cells with `res`x`res` number of points
	int res_0 = std::stoi(argv[3]);

	// Declare changing hyperparameters in the simulation
	int nrows;
	int ncols;
	double step;
	int res;

	Perlin perlin_1;
	nrows = nrows_0 * 1;
	ncols = ncols_0 * 1;
	step = step_0 / 1;
	res = res_0 / 1;
	perlin_1.set_main_grid (nrows, ncols, step);
	perlin_1.set_gradient_field (nrows, ncols);
	perlin_1.set_sub_grid (nrows, ncols, step, res);
	perlin_1.set_dot_grid (nrows, ncols, step, res);
	perlin_1.set_interp_grid (nrows, ncols, step, res);
	perlin_1.set_sub_grad_field (nrows, ncols, res);

	//save_perlin(perlin_1, nrows, ncols, step, res, "1");

	int npart = 2;
	double T = 1;
	double dt = 1e-04;
	Particle particle;
	particle.set_starting_positions(npart, nrows, ncols, step);
	particle.trace_particles(perlin_1, npart, nrows, ncols, res, T, dt);

	return 0;
}