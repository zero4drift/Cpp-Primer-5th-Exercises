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
  for(int (&ib)[4] : ia)
    {
      for(int i : ib)
	cout << i << endl;
    }
  for(size_t i1 = 0; i1 != 3; ++i1)
    {
      for(size_t i2 = 0; i2 != 4; ++i2)
	cout << ia[i1][i2] << endl;
    }
  for(int (*p)[4] = ia; p != ia + 3; ++p)
    {
      for(int *q = *p; q != *p + 4; ++q)
	cout << *q << endl;
    }
}
