////////////////////////////////////////////////////////
//
//		Finding roots of real-valued functions using
//		the Newton–Raphson method
//
//		File : function.hpp
//		Desc : Contains the definition to the real-valued
//					 function and to its derivate
//
//		Written by Balázs Pál @ 2021
//		For Furu and Szigety
//
////////////////////////////////////////////////////////

double f(double x) {
	/*
	This is an ordinary, good behaving, real-valued function, which can be used to
	demonstrate the basic usage of the program. 
	*/
	return x*x - 612.0;
}
double fp(double x) {
	/*
	This is the derivate of the ordinary, good behaving, real-valued function.
	*/
	return 2*x;
}