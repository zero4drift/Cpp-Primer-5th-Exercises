#include <list>
#include <iostream>
#include <algorithm>

using std::list;
using std::cout;
using std::endl;
using std::find;

int main()
{
  list<int> li = {1, 2, 3, 4, 0, 0, 7, 0, 8};
  auto riter = find(li.crbegin(), li.crend(), 0);
  list<int> result(li.cbegin(), riter.base());
  for(const auto &i : result) cout << i << endl;
}
