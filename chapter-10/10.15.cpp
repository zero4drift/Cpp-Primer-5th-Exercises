#include <iostream>

using std::cout;
using std::endl;

int sample(int i)
{
  int x = 5;
  return ([x](int n){return x + n;})(i);
}

int main()
{
  cout << sample(2) << endl;
}
