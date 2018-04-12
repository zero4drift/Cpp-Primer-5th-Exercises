#include <cstddef>
#include <iostream>

using std::size_t;
using std::cout;
using std::endl;

int main()
{
  int ia[10];
  for(size_t i = 0; i < 10; ++i)
    ia[i] = i;			// size_t type object could be implicitly converted to int type
  for(auto i : ia)
    cout << i << endl;
}
