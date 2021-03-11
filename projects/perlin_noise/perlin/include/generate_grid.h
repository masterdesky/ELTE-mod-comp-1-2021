
// Generate the a coordinate field between given limits
vec_2d<double> get_coordinates(int nrows, int ncols,
															 std::vector<double> x_lim,
															 std::vector<double> y_lim);

// Create the grid-cells
vec_2d<int> create_cells(int nrows, int ncols);

// Create sub-cells in which dot products are evaluated
vec_3d<double> create_sub_grid(int res,
															 vec_2d<double> const &coordinates,
															 vec_2d<int> const &cells);

// Return a 2D vector with a given `phi` argument
std::vector<double> get_gradient(double phi);

// Create a discrete vector field of vectors with randomly choosen
// arguments. Vectors are situated in each gridpoints.
vec_2d<double> get_gradient_field(int nrows, int ncols);

// Calculate the dot product between the generated vector field in every
// corner of the grid cells.
vec_2d<double> get_dist_vector_field(int res,
																		 vec_2d<double> const &coordinates,
																		 vec_2d<int> const &cells);

vec_2d<double> get_dot_product(int nrows, int ncols, int res,
															 vec_2d<double>const &coordinates,
															 vec_2d<int> const &cells,
															 vec_2d<double> const &gradient_field,
															 vec_2d<double> const &dist_vector_field);

// Write a 2D vector into a file with arbitrary variables
template <typename T>
void write_to_file(T const &table,
									 std::string filename)
{
  std::ofstream output_file;

  // Save generated gradient field
  output_file.open(filename);

  for(std::size_t i = 0; i < table.size(); i++)
  {
  	for(std::size_t j = 0; j < table[i].size(); j++)
  	{
  		output_file << table[i][j] << ",";
  	}
  	output_file << std::endl;
	}

  output_file.close();
}