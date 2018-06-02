// list<element_type>::iterator and forward_list<element_type>::iterator do not support 'iter += n' operation for that list<element_type> object is not stored in sequence memory.

#include <list>
#include <iostream>

using std::list;
using std::cout;
using std::endl;

int main()
{
  list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // for forawrd_list, forward_list<int>::iterator prev = li.before_begin();
  auto iter = li.begin();
  while(iter != li.end())
    {
      if(*iter % 2)
	{
	  iter = li.insert(iter, *iter);
	  ++(++iter);
	  // for forward_list
	  // iter = li.insert_after(iter, *iter);
	  // prev = iter;
	  // ++iter;
	}
      else
	// for forward_list
	// iter = li.erase_after(prev);
	iter = li.erase(iter);
    }
  for(const auto &i : li)
    cout << i << endl;
}
