# Final projects

One of the requirements for completing the course is to develop and submit a project work, freely chosen from the list below, by the end of the semester. The project should be written entirely in C++, and a corresponding $\LaTeX$ report should be also submitted along with it.

## List of project works
1. *Creating a vector and square matrix `struct`.* On type-level it should have a predefined size, similar to `std::array`. Regular mathematical operations should be made available to used between the created structures. In case of the matrix structure, two of the following methods should be implemented and tested using the created `struct`:
  - Solving linear equation systems, where $A \boldsymbol{x} = \boldsymbol{b}$ and $\boldsymbol{b}$ is known,
  - calculating the determinant,
  - calculating the inverse.

2. *Representation of $3$-dimensional rotations in various ways.* Quaternios, $3 \times 3$ matrices, axis–angle representation and conversions between all of the above.

3. *Creating a polynomial class with $1$ variable.* The class should store the coefficients of the polynomial (which should change dynamically if needed), and needs to support the basic operations: addition, subtraction, product, composition, derivative and the value of the integral at a given domain, finding roots of the polynomial (eg. using Newton's iteration), etc.

4. *Creating a function class with $1$ variable.* The class should store the discretization of a continuous function in an arbitrary representation. The goal is to construct it in a way, that the class can be used for the following tasks:
  - Interpolate the function,
  - calculate definite integrals and derivatives,
  - finding roots and extrema of the function
at any given points.

5. *Creating a histogram class with $1$ variable.* Should have dynamically adjustable boundaries and binning frequency.
