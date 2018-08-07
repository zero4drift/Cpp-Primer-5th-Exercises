#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::function;
using std::vector;
using std::string;
using std::count_if;
using std::cout;
using std::endl;

size_t count_empty(const vector<string> &vs)
{
  function<bool (const string&)> fcn = &string::empty;
  return count_if(vs.cbegin(), vs.cend(), fcn);
}

int main()
{
  vector<string> temp = {"hello", "world", ""};
  cout << count_empty(temp) << endl;
}
