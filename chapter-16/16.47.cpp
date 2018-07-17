#include <utility>
#include <iostream>

using std::cout;
using std::endl;

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f1(int &t1, int &t2)
{
  cout << t1 << " " << t2 << endl;
}

void f2(int &&t1, int &&t2)
{
  cout << t1 << " " << t2 << endl;
}

int main()
{
  int i = 2, j = 4;
  flip(f1, i, j);
  flip(f2, 2, 4);
}
