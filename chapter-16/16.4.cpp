#include <vector>
#include <iterator>
#include <iostream>
#include <list>

using std::vector;
using std::iterator;
using std::cout;
using std::endl;
using std::list;

template <typename T1, typename T2>
iterator<T2*, T1> new_find(iterator<T2*, T1> it1, iterator<T2*, T1> it2, T2 var)
{
  while(it1 != it2)
    {
      if(*it1 == var)
	return it1;
      else
	++it1;
    }
  return it2;
}

int main()
{
  vector<int> vi = {1, 2, 3};
  list<int> li = {1, 2, 3};
  cout << *new_find(vi.begin(), vi.end(), 3) << endl;
}
