#include <iostream>

int main()
{
  int v1 = 0, v2 = 0;
  std::cout << "The sum of " << v1; // that is right
  std::cout << " and " << v2;	    // the former one misses a std::cout
  std::cout << " is " << v1 + v2 << std::endl; // same reason as the former one
  return 0;
}
