#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::ostringstream;
using std::ostream;
using std::cout;
using std::endl;

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

template <typename T> string debug_rep(const T &t)
{
  ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T> string debug_rep(T *p)
{
  ostringstream ret;
  ret << "pointer: " << p;
  if(p)
    ret << " null pointer";
  return ret.str();
}

string debug_rep(const string &s)
{
  return '"' + s + '"';
}

string debug_rep(char *p)
{
  return debug_rep(string(p));
}

string debug_rep(const char *p)
{
  return debug_rep(string(p));
}

template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
  return print(os, debug_rep(rest)...);
}

int main()
{
  errorMsg(cout, "hello", string("world"), 42) << endl;
}
