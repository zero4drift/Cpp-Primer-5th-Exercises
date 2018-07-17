#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T, typename... Args>
void foo(const T &t, const Args&... rest)
{
  cout << sizeof...(Args) << endl;
  cout << sizeof...(rest) << endl;
}

int main()
{
  int i = 0;
  double d = 3.14;
  string s = "how now brown cow";
  foo(i, s, 42, d);		// 3 3 
  foo(s, 42, "hi");		// 2 2
  foo(d, s);			// 1 1
  foo("hi");			// 0 0
}
