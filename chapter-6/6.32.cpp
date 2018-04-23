#include <iostream>

using std::cout;
using std::endl;

int *get(int *arry, int index)
{
  // return arry[index]; arry[index] evaluated and then its value stored in a local temp object, return value as a reference would be binded to this local temp object, which would be invalid in memory when this function terminates.
  return arry + index;
}

int main()
{
  int ia[10];
  for(int i = 0; i != 10; ++i)
    {
      *get(ia, i) = i;
      cout << ia[i] << endl;
    }
}
