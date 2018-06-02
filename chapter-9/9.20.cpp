#include <list>
#include <deque>
#include <iostream>

using std::list;
using std::deque;
using std::cout;
using std::endl;

int main()
{
  list<int> li = {1, 2, 3, 4, 5};
  deque<int> di1;
  deque<int> di2;
  for(const auto &i : li)
    (i % 2) ? di1.push_back(i) : di2.push_back(i);
  for(const auto &j : di1)
    cout << j << endl;
  for(const auto &k : di2)
    cout << k << endl;
}
