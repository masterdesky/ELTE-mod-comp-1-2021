// Define Pi with great precision and calculate it
// during compilation time
constexpr double pi() { return std::atan(1)*4; }

template <typename T>
using vec_2d = std::vector<std::vector<T>>;
template <typename T>
using vec_3d = std::vector<std::vector<std::vector<T>>>;