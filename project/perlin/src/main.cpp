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
#include <algorithm>
#include <functional>

//#include <chrono>
//#include <ctime>

#include <template.hpp>
#include <io.hpp>
#include <flow_field.hpp>
#include <perlin.hpp>
#include <perlin_io.hpp>
#include <particle.hpp>
#include <particle_io.hpp>

int main(int argc, char const *argv[])
{
	if(argc != 8)
	{
		std::cout << "ERROR!\n" << "------" << std::endl;
		std::cout << "NOT ENOUGH ARGUMENTS WERE GIVEN!" << std::endl;
		std::cout << "Usage: ./perlin <nrows> <ncols> <res> <freqs> <npart> <nsteps> <vmax>" << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(EXIT_FAILURE);
	}

	// Does not check for valid input, please
	// try to give sensible arguments when you're executing it
	int nrows = std::stoi(argv[1]);
	int ncols = std::stoi(argv[2]);
	// Resolution of sub-cells
	int res = std::stoi(argv[3]);
	// Number of Perlin noises to stack
	int freqs = std::stoi(argv[4]);

	// Number of particles and updates
	int npart = std::stoi(argv[5]);
	int nsteps = std::stoi(argv[6]);
	// Maximum velocity of particles
	double vmax = std::stoi(argv[7]);


	// Stack Perlin noises to get fractal noise
	ndvector<1,double>::t pool_field;
	ndvector<1,double>::t fractal (res * res);
	for(int i = 0; i < freqs; i++)
	{
		int fr = pow(2, i);
		std::string pfx = std::to_string(fr);

		int nrows_i = nrows * fr;
		int ncols_i = ncols * fr;
		Perlin perlin(nrows_i, ncols_i, res);
		save_perlin(perlin, pfx);

		if(i == 0)
		{
			pool_field = perlin.get_interp_grid();
		}

		// Get the interpolated grid
		auto interp = perlin.get_interp_grid();
		// Adding res to the original
		std::transform(fractal.begin(), fractal.end(), interp.begin(), fractal.begin(),
			             std::plus<double>());
	}

	// Run particle simulation
	Particle particle(pool_field, npart, nsteps, res, vmax);
	save_particle(particle);

	return 0;
}