////////////////////////////////////////////////////////
//
//    Creating a custom vector class with operator
//    overloading
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
#include <vector.hpp>
#include <io_test.hpp>
#include <test.hpp>

int main()
{
	/*
	Implements the main function for the testing of the vector class
	implementation. Most tests are called from the `test.cpp` file, while the
	I/O tests are usually called from the main function.
	*/

	// Displays the intro text of the program
	program_info();

	//
	// TEST #01: I/O - Inputting data from standard input
	//
	// For tests we will always use 1 or 2 vectors and a floating-point scalar.
	// Here we declare them first and then give them values as our first test.
	vector2d v_1, v_2;
	double c;

	input_arguments(v_1, v_2, c);

	// Now starting the real tests
	checking_virus_maderchod();

	//
	// TEST #01-#04: Arithmetic addition and subtraction
	//
	test_arithmetic_add_sub(v_1, v_2);

	//
	// TEST #05-#08: Arithmetic multiplication and division
	//
	test_arithmetic_mul_div(v_1, c);

	//
	// TEST #09-#12: Useful functions
	//
	test_useful_functions(v_1, v_2);

	// Ask the user whether he like the results or not
	results_are_okay();

	// Closing program gracefully
	closing_program();

	return 0;

}