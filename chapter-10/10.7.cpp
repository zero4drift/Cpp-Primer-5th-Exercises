// a: illegal
// b: illegal

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using std::vector;
using std::list;
using std::copy;
using std::fill_n;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  // a
  vector<int> vec;
  list<int> lst;
  int i;
  while(cin >> i)
    lst.push_back(i);
  vec.assign(lst.size(), 0);
  copy(lst.cbegin(), lst.cend(), vec.begin());
  for(const auto &i : vec) cout << i << endl;
  // b
  vector<int> vec2;
  vec2.reserve(10);	     // vec2 still has no elements, it is empty 
  vec2.assign(10, 1);		// without it, fill_n would output undefined result, see the example illustrated in P341
  fill_n(vec2.begin(), 10, 0);
  for(const auto &i : vec2) cout << i << endl;
}
