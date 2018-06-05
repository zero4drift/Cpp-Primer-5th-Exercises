#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int j = 4;
  auto f = [j] () mutable -> bool {int result = j; while(j) --j; return result;};
  cout << f() << endl;
  cout << f() << endl;
  cout << j << endl;
}
