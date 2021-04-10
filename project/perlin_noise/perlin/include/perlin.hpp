////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : generate_grid.hpp
//    Desc : Contains the declaration to the `Perlin` class
//           that directly handles the noise grid generation
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <iostream>

class Perlin {
	/*
	Implements the classic Perlin noise generation. This generation method
	consists of 3 steps:
		1.	Generate a low resolution grid and place unit vectors to every grid
				points with their arguments randomized.
		2.	Overlap a high resolution grid on top of the previous one and take
				the dot product of every single direction vector and the nearest vector
				in the closes grid point of the low resolution grid.
		3.	Interpolate the final high resolution grid to get a smooth gradient
				field at the end.

	Parameters:
	-----------


	
	All return values are explicitly defined to serve a clearer understanding.
	*/
	private:
		int nrows, ncols;
		double step, res;

		// Direction vectors of the low resolution main grid
		ndvector<2,double>::t _main_grid;
		// Randomly set vectors in the grid points of the main grid
		ndvector<2,double>::t _gradient_field;
		// Direction vectors of the high resolution sub grid
		// For every quarter cell in the main grid, it assigns a small, high
		// resolution grid. This means, there are S=(nrows-1)*(ncols-1)*4 number of
		// these sub grids
		ndvector<3,double>::t _sub_grid;
		// The field containing dot products of the sub grid and main grid vectors
		// in every grid points of the high resolution sub grid
		ndvector<1,double>::t _dot_grid;


		// Generate the a coordinate grid between given limits
		ndvector<2,double>::t static
		_get_coordinates(int const &nrows, int const &ncols, double const &step);

		// Return a 2D vector with a given `phi` argument
		ndvector<1,double>::t static
		_get_gradient(double const &phi);

	public:
		// Constructors, destructors
		Perlin() { /* Default constructor */ }
		Perlin(int &nr, int &nc, double &s, int &r)
		{
			/* Standard constructor of the Perlin class. */
			set_parameters(nr, nc, s, r)
			set_main_grid(nrows, ncols, step);
			set_gradient_field(nrows, ncols);
		}

		~Perlin() { std::cout << "Perlin ok." << std::endl; }

		// Set basic parameters
		void set_parameters(int const &nr, int const &nc, double const &s, double const &r)
		{
			nrows = nr;
			ncols = nc;
			step = s;
			res = r;
		}

		// Public methods
		void set_main_grid(int const &nrows, int const &ncols, double const &step);
		ndvector<2,double>::t get_main_grid() { return _main_grid; }

		void set_gradient_field(int const &nrows, int const &ncols);
		ndvector<2,double>::t get_gradient_field() { return _gradient_field; }

		void set_sub_grid()
		ndvector<3,double>::t get_sub_grid{ return _sub_grid; }
		

		/*
		// Create the grid-cells
		create_cells(int const &nrows, int const &ncols);

		// Create sub-cells in which dot products are evaluated
		create_sub_grid(int const &res,
										ndvector<2,double>::t const &coordinates,
										ndvector<2,int>::t const &cells);

		// Create a discrete vector field of vectors with randomly choosen
		// arguments. Vectors are situated in each gridpoints.
		ndvector<2,double>::t
		get_gradient_field(int const &nrows, int const &ncols);

		// Calculate the dot product between the generated vector field in every
		// corner of the grid cells.
		ndvector<2,double>::t
		get_dist_vector_field(int const &res,
													ndvector<2,double>::t const &coordinates,
													ndvector<2,int>::t const &cells);

		ndvector<2,double>::t
		get_dot_product(int const &nrows, int const &ncols, int const &res,
										ndvector<2,double>::t const &coordinates,
										ndvector<2,int>::t const &cells,
										ndvector<2,double>::t const &gradient_field,
										ndvector<2,double>::t const &dist_vector_field);

		*/
};