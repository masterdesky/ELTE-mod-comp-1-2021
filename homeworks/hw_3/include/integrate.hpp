////////////////////////////////////////////////////////
//
//    Numerical integration
//
//    File : integrate.hpp
//    Desc : Contains the integration methods
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

std::vector<double>
get_X(int const &N, double const &a)
{
  // Determine the x_n sampling points
  std::vector<double> X (N);
  // Set the 2 end points
  X[0] = 0; X[N] = a;
  // Determine the step size between sampling points
  double step = a / (N-1);
  // Set the N-2 intermediate points
  for(int x = 1; x < N-1; x++)
  {
    X[x] = x * step;
  }

  return X;
}

double
rectangle(String string, int const &N, double const &a)
{
  // Get the x_n sampling points
  auto X = get_X(N, a);
  // Determine the centers of the neighbouring sampling points
  std::vector<double> X_m (N-1);
  for(int m = 0; m < N-1; m++)
  {
    X_m[m] = (X[m] + X[m+1])/2;
  }
  // Determine the f(x_m) values of the curve
  auto M = string.sample(X_m);

  // Determine the sum of the area of the rectangles
  double A = 0;
  for(int a = 0; a < N-1; a++)
  {
    A += M[a] * (X[a+1] - X[a]);
  }

  return A;
}

double
trapezoid(String string, int const &N, double const &a)
{
  // Get the x_n sampling points
  auto X = get_X(N, a);
  // Determine the f(x_n) values of the curve
  auto Y = string.sample(X);

  // Determine the sum of the area of the trapezoids
  double A = 0;

  return A;
}