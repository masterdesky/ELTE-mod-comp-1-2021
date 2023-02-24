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

double
rectangle(std::function<double(double const &)> fp, int const &N, double const &a, double const &b)
{
  // Get the x_n sampling points
  auto X = get_X(N, a, b);
  
  // Determine the centers of the neighbouring sampling points
  std::vector<double> X_m (N-1);
  for(int m = 0; m < N-1; m++)
  {
    X_m[m] = (X[m] + X[m+1])/2;
  }

  // Determine the f(x_m) values of the curve
  std::vector<double> M (N-1);
  for(int m_i = 0; m_i < N-1; m_i++)
  {
    M[m_i] = fp(X[m_i]);
  }

  // Determine the sum of the area of the rectangles
  double A = 0;
  for(int a_i = 0; a_i < N-1; a_i++)
  {
    A += M[a_i] * (X[a_i+1] - X[a_i]);
  }

  return A;
}

double
trapezoid(std::function<double(double const &)> fp, int const &N, double const &a, double const &b)
{
  // Get the x_n sampling points
  auto X = get_X(N, a, b);
  // Determine the f(x_n) values of the curve
  std::vector<double> Y (N);
  for(int y_i = 0; y_i < N; y_i++)
  {
    Y[y_i] = fp(X[y_i]);
  }

  // Determine the sum of the area of the trapezoids
  double A = 0;
  for(int a_i = 0; a_i < N-1; a_i++)
  {
    A += (Y[a_i] + Y[a_i+1])/2 * (X[a_i+1] - X[a_i]);
  }

  return A;
}

double
Simpson(std::function<double(double const &)> fp, int const &N, double const &a, double const &b)
{
  // Get the x_n sampling points
  auto X = get_X(N, a, b);

  // Determine the sum of the area of the trapezoids
  return (2*rectangle(fp, N, a, b) + trapezoid(fp, N, a, b)) / 3;
}