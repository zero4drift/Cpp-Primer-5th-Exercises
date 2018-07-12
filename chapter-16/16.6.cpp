// begin function which accepts an array argument returns the pointer points to the first element of array;

// end function returns the pointer points to the tail off element of array.

#include <iostream>

using std::cout;
using std::endl;

template <typename T1, unsigned N>
const T1 *new_begin(const T1 (&array)[N])
{
  return array;
}

template <typename T1, unsigned N>
const T1 *new_end(const T1 (&array)[N])
{
  return &array[N-1];
}

int main()
{
  int a[3] = {1, 2, 3};
  for(auto first = new_begin(a); a != new_end(a); ++first)
    cout << *first << endl;
}
