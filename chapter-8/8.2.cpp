#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

extern istream &unlimit_inputs(istream &);

int main()
{
  int i = 0;
  (unlimit_inputs(cin)) >> i;
  cout << i << endl;
}
