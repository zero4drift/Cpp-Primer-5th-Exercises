#include <iostream>

using std::cout;
using std::endl;

void print(const int ia[10])	// the real type of parameter is const int*
{
  for(size_t i = 0; i != 10; ++i) // it is dangerous, the array argument' length may be shorter than 10, but compiler would allow it, that results in an undefined behaviour
    cout << ia[i] << endl;
}

// correct one
void print(const int (&ia)[10])
{
  for(size_t i = 0; i != 10; ++i)
    cout << ia[i] << endl;
}
