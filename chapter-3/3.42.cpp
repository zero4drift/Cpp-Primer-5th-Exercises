#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

int main()
{
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int ia[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // this array could be initialized implictily
  for(decltype(v.size()) index = 0; index < v.size(); ++index)
    ia[index] = v[index];
  for(auto i : ia)
    cout << i << endl;
}
