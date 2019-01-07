// See StrVec.h and StrVec.cpp.

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "StrVec.hpp"

using std::malloc;
using std::free;
using std::bad_alloc;
using std::cout;
using std::endl;

void *operator new(size_t size)
{
  cout << "operator new" << endl;
  if(void *mem = malloc(size))
    return mem;
  else
    throw bad_alloc();
}

void operator delete(void *mem) noexcept
{
  cout << "operator delete" << endl;
  free(mem);
}

int main()
{
  StrVec({"hello", "world"});
}
