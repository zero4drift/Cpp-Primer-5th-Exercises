#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int x[10];
  int *p = x;
  cout << sizeof(x)/sizeof(*x) << endl; // 10
  cout << sizeof(p)/sizeof(*p) << endl; // 2, but it depends on certain machine, as my pc is 64-bits arch, a pointer consumes 64 bits, which is 8 bytes, so this expression causes undefined behaviour.
}
