#include <iostream>

using std::cout;

template <typename T1, unsigned N>
void print(const T1 (&array)[N])
{
  for(unsigned i = 0; i != N; ++i)
    cout << array[i] << " ";
}

int main()
{
  int a[3] = {1, 2, 3};
  print(a);
}
