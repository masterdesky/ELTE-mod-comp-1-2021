////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : io.hpp
//    Desc : Handles the I/O in the project
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

class PerlinIO {
	public:
		template <typename T>
		void write_to_file(T const &table,
	            				 std::string filename);
	private:
		ndvector<1,double>::t
		flatten();
}