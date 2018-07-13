#include <iostream>

using std::cout;
using std::endl;

template <typename T, unsigned N>
constexpr unsigned number(T (&array)[N])
{
  return N;
}

int main()
{
  int a[] = {1, 2, 3};
  cout << number(a) << endl;
}
