#include <iostream>

using std::cout;
using std::endl;

int ia[3][4] =
  {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
  };

int main()
{
  for(auto &ib : ia)
    {
      for(auto i : ib)
	cout << i << endl;
    }
  for(auto i1 = 0; i1 != 3; ++i1)
    {
      for(auto i2 = 0; i2 != 4; ++i2)
	cout << ia[i1][i2] << endl;
    }
  for(auto p = ia; p != ia + 3; ++p)
    {
      for(auto q = *p; q != *p + 4; ++q)
	cout << *q << endl;
    }
}
