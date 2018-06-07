#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>

using std::unique_copy;
using std::vector;
using std::list;
using std::inserter;
using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Please enter integers: " << endl;
  vector<int> vi;
  int i;
  while(cin >> i)
    vi.push_back(i);
  if(!vi.size()) return -1;
  list<int> li;
  unique_copy(vi.cbegin(), vi.cend(), inserter(li, li.begin()));
  cout << "Unique integers among your inputs: " << endl;
  for(const auto &i : li)
    cout << i << endl;
}
