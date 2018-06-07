#include <algorithm>
#include <vector>
#include <forward_list>
#include <iterator>
#include <iostream>

using std::copy;
using std::vector;
using std::forward_list;
using std::inserter;
using std::back_inserter;
using std::front_inserter;
using std::cout;
using std::endl;

int main()
{
  vector<int> vi1, vi2, vi4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  forward_list<int> fl;
  // same as vi4
  copy(vi4.cbegin(), vi4.cend(), inserter(vi1, vi1.begin()));
  // same as vi4
  copy(vi4.cbegin(), vi4.cend(), back_inserter(vi2));
  // reverse order of vi4
  copy(vi4.cbegin(), vi4.cend(), front_inserter(fl));
  cout << "for the one using inserter: " << endl;
  for(const auto &i : vi1)
    cout << i << endl;
  cout << "for the one using back_inserter: " << endl;
  for(const auto &i : vi2)
    cout << i << endl;
  cout << "for the one using front_inserter: " << endl;
  for(const auto &i : fl)
    cout << i << endl;
}
