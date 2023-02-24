////////////////////////////////////////////////////////
//
//    Finding roots of real-valued functions using
//    the Newton-Raphson method
//
//    File : newton.hpp
//    Desc : Implements the Newton-Raphson method
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <math.h>

template <typename F, typename Fp, typename T>
T Newton(F f, Fp fp, T &x_0, int &n_iter, T &epsilon) {
	/*
	Implements the Newton–Raphson method. This method takes advantage of that
	if we consider a real-valued function `f` and its derivative `f'` and then
	randomly chose a point `x_0`, then the point `x_1`, where
	
	```
	x_1 = x_0 - [ f(x_0) / f'(x_0) ]
	```
	will be closer to the root of the function `f`, than `x_0` is. If we're using
	this method iteratively with an appropriately selected starting point `x_0`,
	then `x_n` will converge into the closest root of the function `f`.

	Reference: https://mathworld.wolfram.com/NewtonsMethod.html


	Parameters:
	-----------
	f : function template
		The input real-valued function.

	fp : function template
		The derivate of the input real-valued function.

	x_0 : type template
		Starting guess for the root, marked as `x_0` similarly in the description
		above.

	n : integer
		The maximum number of iterations when executing the Newton-Raphson method.

	epsilon : type template 
		Precision of the algorithm.
	*/

	std::cout << "Starting the Newton-Raphson method..." << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	// The variable `x_n` will be always the placeholder for the next guess in the
	// consecutive iterations.
	double x_n = x_0;
	std::cout << "Initial x_0 = " << x_0 << std::endl;
	std::cout << "Initial f(x_0) = " << f(x_0) << std::endl;
	std::cout << "Initial f'(x_0) = " << fp(x_0) << std::endl;
	std::cout << "\n" << std::endl;

	// Perform a maximum of `n_iter` iterations. If iteration limit is reached,
	// but no good approximation was achieved, tell the user, that you're very
	//  very VERY sorry and that it hopefully never ever happen again.
	for(int i = 0; i < n_iter; i++) {
		std::cout << "ITERATION " << i+1 << std::endl;

		// Calculate `x_n` which will take the value of x_{n-1} in the next
		// iteration of the loop.
		x_n = x_n - f(x_n)/fp(x_n);

		std::cout << "Current x_n = " << x_n << std::endl;
		std::cout << "Current f(x_n) = " << f(x_n) << std::endl;
		std::cout << "Current f'(x_n) = " << fp(x_n) << std::endl;
	
		// Stop if accuracy limit is reached before finishing all iterations
		if(fabs(f(x_n)) <= epsilon) {
			std::cout << "\n" << std::endl;
			std::cout << "FOUND SOLUTION! z_0 = " << x_n << std::endl;
			std::cout << "Ending iteration..." << std::endl;
			std::cout << "Good bye! :)" << std::endl;
			return 0;
		}

		std::cout << "-------------------------------------\n" << std::endl;

	}
	std::cout << "I'M SORRY! No correct approximation were found..." << std::endl;
	std::cout << "I p-promise, I'll do b-better next time... \"ToT" << std::endl;
	std::cout << "Now I'm aborting the iteration and everything..." << std::endl;
	std::cout << "Good bye, please don't be mad at me!! >o<" << std::endl;

	return 0;
}
