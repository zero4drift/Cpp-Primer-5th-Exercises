// See StrVec.h.

#include <iostream>
#include "Vec.h"

using std::cout;
using std::endl;

int main()
{
  Vec<int> vi1 = {1, 2, 3};
  Vec<int> vi2 = {1, 2, 4};
  cout << vi1[0] << endl;
  cout << (vi1 == vi2) << endl;
}

