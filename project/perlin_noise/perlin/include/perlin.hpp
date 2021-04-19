////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : perlin.hpp
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
		// Direction vectors of the low resolution main grid
		ndvector<2,double>::t _main_grid;
		// Randomly set vectors in the grid points of the main grid
		ndvector<2,double>::t _gradient_field;
		// Direction vectors of the high resolution sub grid
		// For every quarter cell in the main grid, it assigns a small, high
		// resolution grid. This means, there are S=(nrows-1)*(ncols-1)*4 number of
		// these sub grids
		ndvector<2,double>::t _sub_grid;
		// Indices of the main grid points in cell corners per cells
		ndvector<2,int>::t _cell_corners;
		// Indices of the sub grid points in cell corners per cells
		ndvector<2,int>::t _sub_cell_corners;
		// Distance vector field
		ndvector<3,double>::t _dist_field;
		// The field containing dot products of the sub grid and main grid vectors
		// in every grid points of the high resolution sub grid
		ndvector<2,double>::t _dot_grid;
		// List of nearest cell corners to a sub grid point
		ndvector<1,int>::t _ngp;
		// The interpolated grid which will be the final
		ndvector<1,double>::t _interp_grid;
		// Gradient field of the final interpolated grid. Contains gradient vectors
		// in every sub grid point of the Perlin noise
		ndvector<2,int>::t _sub_grad_field;


		// Generate the a coordinate grid between given limits
		ndvector<2,double>::t static
		_get_coordinates(int const &nrows, int const &ncols, double const &step);

		// Return a 2D vector with a given `phi` argument
		ndvector<1,double>::t static
		_get_gradient(double const &phi);

		ndvector<2,int>::t
		_set_cell_corners(int const &nrows, int const &ncols);

		ndvector<2,int>::t
		_set_sub_cell_corners(int const &nrows, int const &ncols, int &res);

		ndvector<1,int>::t
		_get_current_cell(ndvector<1,double>::t const &p, int const &nrows, int const &ncols, double const &step);

		double
		_interpolate(double const &d0, double const &d1, double const &w);

	public:
		/* Constructors, destructors */

		Perlin() { /* Default constructor */ }
		Perlin(int &nrows, int &ncols, double &step, int &res)
		{
			/* Standard constructor of the Perlin class. */
			set_main_grid(nrows, ncols, step);
			set_gradient_field(nrows, ncols);
			set_sub_grid(nrows, ncols, step, res);
			set_dot_grid(nrows, ncols, step, res);
			set_interp_grid(nrows, ncols, step, res);
		}
		~Perlin() { std::cout << "Perlin ok." << std::endl; }

		/* Public methods */

		void set_main_grid(int const &nrows, int const &ncols, double const &step);
		ndvector<2,double>::t get_main_grid() { return _main_grid; }

		void set_gradient_field(int const &nrows, int const &ncols);
		ndvector<2,double>::t get_gradient_field() { return _gradient_field; }

		void set_sub_grid(int const &nrows, int const &ncols, double const &step, double const &res);
		ndvector<2,double>::t get_sub_grid() { return _sub_grid; }
		ndvector<2,int>::t get_cell_corners() { return _cell_corners; }
		ndvector<2,int>::t get_sub_cell_corners() { return _sub_cell_corners; }

		void set_dot_grid(int const &nrows, int const &ncols, double const &step, double const &res);
		ndvector<2,double>::t get_dot_grid() { return _dot_grid; }

		void set_ngp(int const &nrows, int const &ncols, double const &step, double const &res);
		ndvector<1,int>::t get_ngp() { return _ngp; }

		void set_interp_grid(int const &nrows, int const &ncols, double const &step, double const &res);
		ndvector<1,double>::t get_interp_grid() { return _interp_grid; }

		void set_sub_grad_field(int const &nrows, int const &ncols, double const &res);
		ndvector<2,int>::t get_sub_grad_field() { return _sub_grad_field; }
};