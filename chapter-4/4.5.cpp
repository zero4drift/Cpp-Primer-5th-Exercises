#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int i = -30 * 3 + 21 / 5;	// -86
  int j = -30 + 3 * 21 / 5;	// -18
  int k = 30 / 3 * 21 % 5;	// 0
  int x = -30 / 3 * 21 % 4;	// -2
  cout << i << " " << j << " " << k << " " << x << endl;
}
