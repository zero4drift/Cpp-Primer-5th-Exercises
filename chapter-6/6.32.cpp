#include <iostream>

using std::cout;
using std::endl;

int &get(int *arry, int index)
{
  // legal, for that this function's return type is int&, which is reference to element in arry
  return arry[index];		// [] operator's evaluated result is a left value
}

int main()
{
  int ia[10];
  for(int i = 0; i != 10; ++i)
    {
      get(ia, i) = i;
      cout << ia[i] << endl;
    }
}
