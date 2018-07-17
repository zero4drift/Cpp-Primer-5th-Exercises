#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T>
ostream &print(ostream &os, const T &t)
{
  return os << t;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
  os << t << ", ";
  return print(os, rest...);
}

int main()
{
  print(cout, 3) << endl;
  print(cout, 3, "hello world") << endl;
  print(cout, 3, 3.14, "hello", string("world"), '!') << endl;
}
