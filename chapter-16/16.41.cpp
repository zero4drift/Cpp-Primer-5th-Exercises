#include <type_traits>

using std::make_unsigned;

template <typename T>
auto sum(T a, T b) -> typename make_unsigned<T>::type
{
  return a + b;
}
