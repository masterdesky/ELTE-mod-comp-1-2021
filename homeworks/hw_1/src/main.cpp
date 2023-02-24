////////////////////////////////////////////////////////
//
//		Finding roots of real-valued functions using
//		the Newton–Raphson method
//
//		File : main.cpp
//		Desc : Contains the main function of the project
//
//		Written by Balázs Pál @ 2021
//		For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <newton.hpp>
#include <functions.hpp>

int main(int argc, char const *argv[])
{
	/*
	Implements the main function for the Newton–Raphson method. Predefined
	function definitions can be found in the `function.hpp` header file.
	*/
	if(argc != 4)
	{
		std::cout << "ERROR!\n" << "------" << std::endl;
		std::cout << "INCORRECT NUMBER OF ARGUMENTS WERE GIVEN!" << std::endl;
		std::cout << "Usage: ./newton <x_0> <n_iter> <epsilon>" << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(EXIT_FAILURE);
	}

	double x_0 = std::stod(argv[1]);
	int n_iter = std::stoi(argv[2]);
	double epsilon = std::stod(argv[3]);

	// The `f` and `fp` functions should be always correspond to the same, real-
	// valued function! Otherwise the whole program will brake, and some totally
	// nonsense results will be acquired, but that should be quite obvious...
	Newton(
					f,				// Function `f`
					fp,				// Derivate of function `f`
					x_0,			// Starting guess for `z_0`
				 	n_iter,		// Maximum number of iterations
				 	epsilon		// Maximal accuracy of calculation 						
				);
	
	return 0;
}