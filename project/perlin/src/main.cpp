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

//#include <chrono>
//#include <ctime>

#include <perlin.hpp>
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

	// Does not check for valid input, please
	// try to give sensible arguments when you're executing it
	int nrows_0 = std::stoi(argv[1]);
	int ncols_0 = std::stoi(argv[2]);
	
	// Resolution of sub-cells
	int res = std::stoi(argv[3]);

	// Declare changing hyperparameters in the simulation
	int nrows;
	int ncols;

	// Frequency 1
	nrows = nrows_0 * 1;
	ncols = ncols_0 * 1;
	Perlin perlin_1(nrows, ncols, res);
	save_perlin(perlin_1, nrows, ncols, res, "1");

	// Frequency 2
	nrows = nrows_0 * 2;
	ncols = ncols_0 * 2;
	Perlin perlin_2(nrows, ncols, res);
	save_perlin(perlin_2, nrows, ncols, res, "2");

	// Frequency 4
	nrows = nrows_0 * 4;
	ncols = ncols_0 * 4;
	Perlin perlin_4(nrows, ncols, res);
	save_perlin(perlin_4, nrows, ncols, res, "4");

	// Frequency 8
	nrows = nrows_0 * 8;
	ncols = ncols_0 * 8;
	Perlin perlin_8(nrows, ncols, res);
	save_perlin(perlin_8, nrows, ncols, res, "8");

	/*
	int npart = 2;
	double T = 1;
	double dt = 1e-03;
	Particle particle;
	particle.set_starting_position(nrows, ncols);
	particle.trace_particle(perlin_1, nrows, ncols, res, T, dt);
	*/
	return 0;
}