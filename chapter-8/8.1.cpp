#include <iostream>

using std::istream;
using std::cout;
using std::endl;

istream &unlimit_inputs(istream &is)
{
  char c;
  while(!is.eof())
    {
      is >> c;
      cout << c << endl;
    }
  is.clear();
  return is;
}
