////////////////////////////////////////////////////////
//
//    Creating 2D Perlin noise art in C++ by implementing
//    https://mrl.cs.nyu.edu/~perlin/paper445.pdf
//
//    File : template.cpp
//    Desc : Contains template and constant definitions
//    Tabsize : 2 spaces
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigetty
//
////////////////////////////////////////////////////////

#include <cmath>
#include <vector>

// Define Pi with great precision and calculate it during compilation time
constexpr double pi() { return std::atan(1)*4; }


// Define an arbitrary N-dimensional vector class
// Based on this blog post's totally convenient solution:
// - https://bznein.github.io/general/programming/cpp/templates/learn/2018/12/14/A-templated-multidimensional-vector.html
// - https://github.com/bznein/intent/blob/master/intent.h
// KNOWN ISSUES:
//   -  static_cast can overflow if `dims` is bigger, than the size limit of
//      unsigned int.
//   -  Choosing a dimension smaller than 0 can cause an error in static_cast
//      since we're casting a size_t type to unsigned int.
//   -  Choosing a dimension smaller than 0 will cause the recursion to become
//      an infinite loop and will cause a fatal error, because in this case the
//      template instantiation depth exceeds the maximum (eg. 900 for g++).

// 1. Define the recursive `ndvector` struct
// The variable method `t` corresponds to the type of the data in the vector
template<size_t dims, typename T>
struct ndvector
{
	// Storing the dimension of every level of the recursion for easier I/O later
	unsigned int d = static_cast<unsigned int>(dims);
	
	// Recursively calling an std::vector<T> as the template argument for an
	// outer std::vector<T>, `dims` times in total. The recursion is done by
	// calling the `ndvector` structure with one less number of dimensions in
	// every recursive step.
	// Note: there is a small typo in the blog post (`vec` needs to be `type`
	// or `t` as I marked it in this code).
	typedef std::vector<typename ndvector<dims - 1, T>::t> t;
};

// 2. Create a stopping rule for the recursion above
// A vector with type `T` and 0 dimension should be a single scalar of type `T`
// encoded as a variable called `t` here.
template<typename T>
struct ndvector<0,T>
{
	//unsigned int d = 0;
	typedef T t;
};