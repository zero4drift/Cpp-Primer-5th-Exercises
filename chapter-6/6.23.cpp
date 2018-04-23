#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void print(const int ia[], size_t size)
{
  for(size_t i = 0; i != size; ++i)
    cout << ia[i] << endl;
}

void print(const int (&array)[2])
{
  for(int elem : array)
    cout << elem << endl;
}

int main()
{
  int i = 0, j[2] = {0, 1};
  print(&i, 1);
  print(j);
}
