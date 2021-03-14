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

class Perlin {
	/*
	
	All return values are explicitly defined to serve a clearer understanding.
	*/
	public:
		// Generate the a coordinate grid between given limits
		ndvector<2,double>::t
		get_coordinates(int nrows, int ncols,
										ndvector<1,double>::t x_lim,
										ndvector<1,double>::t y_lim);

		// Create the grid-cells
		ndvector<2,int>::t
		create_cells(int nrows, int ncols);

		// Create sub-cells in which dot products are evaluated
		ndvector<3,double>::t
		create_sub_grid(int res,
										ndvector<2,double>::t const &coordinates,
										ndvector<2,int>::t const &cells);

		// Create a discrete vector field of vectors with randomly choosen
		// arguments. Vectors are situated in each gridpoints.
		ndvector<2,double>::t
		get_gradient_field(int nrows, int ncols);

		// Calculate the dot product between the generated vector field in every
		// corner of the grid cells.
		ndvector<2,double>::t
		get_dist_vector_field(int res,
													ndvector<2,double>::t const &coordinates,
													ndvector<2,int>::t const &cells);

		ndvector<2,double>::t
		get_dot_product(int nrows, int ncols, int res,
										ndvector<2,double>::t const &coordinates,
										ndvector<2,int>::t const &cells,
										ndvector<2,double>::t const &gradient_field,
										ndvector<2,double>::t const &dist_vector_field);

	private:
		// Return a 2D vector with a given `phi` argument
		ndvector<1,double>::t
		get_gradient(double phi);
}