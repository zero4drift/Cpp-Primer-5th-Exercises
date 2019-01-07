#include <iostream>
#include "Chapter6.hpp"

using std::cin;
using std::cout;
using std::endl;

unsigned fract(unsigned x)
{
  unsigned rel = 1;
  while(x > 0)
    rel *= x--;
  return rel;
}
