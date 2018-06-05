#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::bind;
using std::placeholders::_1;
using std::string;
using std::vector;
using std::stable_partition;
using std::cout;
using std::cin;
using std::endl;

bool check_size(const string &s, string::size_type sz)
{
  return s.size() >= sz;
}

int main()
{
  cout << "Please enter a string: " << endl;
  string s;
  cin >> s;
  vector<int> vi = {1, 2, 3, 4, 5, 6};
  auto iter = stable_partition(vi.begin(), vi.end(),
		      bind(check_size, s, _1));
  if(iter == vi.end()) cout << "No desired element found in vector" << endl;
  else cout << *iter << endl;
}
