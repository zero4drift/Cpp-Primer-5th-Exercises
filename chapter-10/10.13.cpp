#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::partition;

bool greater_than_five(const string &s)
{
  return s.size() >= 5;
}

int main()
{
  vector<string> vs =
    {"hello", "world", "is", "everything", "all", "right"};
  auto iter = partition(vs.begin(), vs.end(), greater_than_five);
  for(auto beg = vs.begin(); beg != iter; ++beg)
    cout << *beg << endl;
}
