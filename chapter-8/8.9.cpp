#include <sstream>
#include <string>
#include <iostream>

using std::istringstream;
using std::istream;
using std::string;

extern istream &unlimit_inputs(istream &is);

int main()
{
  string s = "hello world";
  istringstream is(s);
  unlimit_inputs(is);
}
