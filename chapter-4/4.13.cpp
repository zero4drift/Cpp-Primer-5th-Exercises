#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int i;
  double d;
  d = i = 3.5;			// d = 3.0, i = 3
  cout << d << " " << i << endl;
  i = d = 3.5;			// d = 3.5, i = 3
  cout << d << " " << i << endl;
}
