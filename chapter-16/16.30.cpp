#include <iostream>
#include "Blob.h"

using std::cout;
using std::endl;

int main()
{
  Blob<int> b = {1, 2, 3};
  auto length = b.size();
  for(size_t index = 0; index != length; ++index)
    cout << b[index] << endl;
}
