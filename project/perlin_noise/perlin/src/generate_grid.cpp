////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : generate_grid.cpp
//    Desc : Contains the definition to the `Perlin` class
//           that directly handles the noise grid generation
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <math.h>
#include <algorithm>
#include <vector>
#include <random>

#include <template.hpp>
#include <generate_grid.hpp>

// Generate a 2D coordinate grid between given X and Y limits
ndvector<2,double>::t
Perlin::get_coordinates(int const &nrows, int const &ncols,
												ndvector<1,double>::t const &x_lim,
												ndvector<1,double>::t const &y_lim)
{
	// Declaration of the coordinate grid
	ndvector<2,double>::t coords (nrows * ncols);
	
	// Calculate stepsize in each direction
	double x_step = (x_lim[1] - x_lim[0]) / ncols; // X direction perp. to cols
	double y_step = (y_lim[1] - y_lim[0]) / nrows; // Y direction perp. to rows

	// Calculate coordinates of grid points
	for(int i = 0; i < nrows; i++)
	{
		for(int j = 0; j < ncols; j++)
		{
			coords[i * ncols + j] = {j*x_step, i*y_step};
		}
	}

	return(coords);
}

// Return a 2D vector with a given `phi` argument
ndvector<1,double>::t
Perlin::get_gradient(double const &phi)
{
	ndvector<1,double>::t gradient {sin(phi), cos(phi)};

	return(gradient);
}


// Create the grid-cells
ndvector<2,int>::t
Perlin::create_cells(int const &nrows, int const &ncols)
{
	// Number of cells in each rows and columns
	int crows = nrows - 1;
	int ccols = ncols - 1;
	ndvector<2,int>::t cells (crows * ccols);

	// Iterate over all points, except the last row and the last column.
	// The iteration is basically over the possible upper left corners for a cell.
	for(int i = 0; i < crows; i++)
	{
		for(int j = 0; j < ccols; j++)
		{
			int idx = i * ccols + j; // Index for cells
			int c = i * ncols + j;   // Index for coordinates
	  	
	  	// Gather the coordinates of cell's corners.
	  	// Coordinates are in the upper right quarter of the coordinate system
	  	// and they're situated in the following order in the `cells` vector:
	  	// 1: Bottom left
	  	// 2: Bottom right
	  	// 3: Upper left
	  	// 4: Upper right
	  	cells[idx] = {c, c+1, c+ncols, c+ncols+1};
	  }
  }

	return(cells);
}


// Create sub-cells in which dot products are evaluated
ndvector<3,double>::t
Perlin::create_sub_grid(int const &res,
												ndvector<2,double>::t const &coords,
												ndvector<2,int>::t const &cells)
{
	// Placeholder for the subcells
	// Each entry consist of a cell
	ndvector<3,double>::t sub_grid (
														(int)cells.size(),
														ndvector<2,double>::t (
																4*res*res,
																ndvector<1,double>::t (2)
														)
												);

	// Iterate over all cells
	// i : index of a cell
	for(std::size_t i = 0; i < cells.size(); i++)
	{
		// Identify coordinates of the current cell's borders
		double x_min = coords[cells[i][0]][0]; // x_min from bottom left corner
		double y_min = coords[cells[i][0]][1]; // y_min from bottom left corner
		double x_max = coords[cells[i][3]][0]; // x_max from upper right corner
		double y_max = coords[cells[i][3]][1]; // y_max from upper right corner

		// Iterate over the corners of the current cell
		// j : index of the `i`-th cell's corner
		// --------------
		// Define limits for 
		// j=0: x_min-x_max/2 and y_min-y_max/2 // Bottom left
		// j=1: x_max/2-x_max and y_min-y_max/2 // Bottom right
		// j=2: x_min-x_max/2 and y_max/2-y_max // Upper left
		// j=3: x_max/2-x_max and y_max/2-y_max // Upper right
		ndvector<2,double>::t sub_cell_lims {
																	{x_min, x_max/2, y_min, y_max/2},
																	{x_max/2, x_max, y_min, y_max/2},
																	{x_min, x_max/2, y_max/2, y_max},
																	{x_max/2, x_max, y_max/2, y_max}	
																};

		// Placeholder for the concatenated four subcells inside the current cell
		ndvector<2,double>::t temp_cell;

		// Finally the actual iteration over the cell corners
		for(std::size_t j = 0; j < cells[i].size(); j++)
		{
			// Identify the limits of the current corner's sub-cell
			auto corners = sub_cell_lims[j];
			// Create a point grid inside the subcell
			auto sub_coords = get_coordinates(res, res,
																				{corners[0], corners[1]},
																				{corners[2], corners[3]});
			// Append the sub-cell to the current cell
			temp_cell.insert(temp_cell.end(),
											 sub_coords.begin(), sub_coords.end());
		}
		// Append the subcell the cell to the 3D table
		sub_grid[i] = temp_cell;
	}

	return(sub_grid);
}


// Create a discrete vector field of vectors with randomly choosen
// arguments. Vectors are situated in each gridpoints.
ndvector<2,double>::t
Perlin::get_gradient_field(int const &nrows, int const &ncols)
{
	// Initialize the Mersenne-Twister RNG to choose
	// values from a uniform distribution between 0 and 2pi
  std::random_device Randomized;
  std::mt19937_64 Generate(Randomized());
  std::uniform_real_distribution<> Distribution(0, 2*pi());

  // Placeholder for the gradient field
  ndvector<2,double>::t gradient_field (nrows * ncols);

  // Generate the gradient field
  for(std::size_t i = 0; i < gradient_field.size(); i++)
  {
  	double phi = Distribution(Generate);
  	gradient_field[i] = get_gradient(phi);
  }

  return(gradient_field);
}


// Calculate the dot product between the generated vector field in every
// corner of the grid cells.
ndvector<2,double>::t
Perlin::get_dist_vector_field(int const &res,
															ndvector<2,double>::t const &coords,
															ndvector<2,int>::t const &cells)
{
	// Placeholder for the distance matrix. Contains the difference of
	// cell corners and sub-cell points.
	ndvector<2,double>::t dist_vector_field (
																(int)cells.size() * (4 * res * res),
																ndvector<1,double>::t (2)
															);
	auto sub_grid = create_sub_grid(res,
																	coords, cells);

	// Calculate distance vectors
	// First iterate over cells
	// i: first coordinate of `sub_grid`, marks cells
	for(std::size_t i = 0; i < cells.size(); i++)
	{
		// Iterate over sub-coordinates
		for(std::size_t k = 0; k < sub_grid[i].size(); k++)
		{
			// Identify the current cell's corners
			int j = floor((int)k/(res*res));
			// Identify vectors to calculate distance between
			auto a = coords[cells[i][j]];	// Closest corner's coordinates
			auto b = sub_grid[i][k];						// Current sub-point's coordinates
			ndvector<1,double>::t d (2);				// Placeholder for distance vector

			// Calculate distance between vectors `a` and `b`: d = a - b
			std::transform(a.begin(), a.end(), b.begin(), d.begin(),
										 std::minus<double>());
			
			// Add current distance vector to the final data table
			dist_vector_field[(i * 4*res*res) + (j * res*res) + (k)] = d;
		}
	}

	return(dist_vector_field);
}


ndvector<2,double>::t
Perlin::get_dot_product(int const &nrows, int const &ncols, int const &res,
												ndvector<2,double>::t const &coordinates,
												ndvector<2,int>::t const &cells,
												ndvector<2,double>::t const &gradient_field,
												ndvector<2,double>::t const &dist_vector_field)
{
	// Placeholder for the dot-product table
	vec_2d<double> dot_product (
														(int)cells.size(),
														ndvector<1,double>::t (4 * res * res)
													);

	return(dot_product);
}