#include <cstddef>

using std::size_t;

int main()
{
  constexpr size_t array_size = 10;
  int ia[array_size];
  for(size_t ix = 1; ix <= array_size; ++ix) // illegal, ix starts with 0 and should be smaller than array_size
    ia[ix] = ix;
}
