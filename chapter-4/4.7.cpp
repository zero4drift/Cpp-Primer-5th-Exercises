// overflow means that one computed result is beyond the representation range of one certain type

#include <iostream>

int main()
{
  int i = 2147483648;
  unsigned j = 4294967296;
  char k = 256;
  std::cout << i << " " << j << " " << k << std::endl;
}
