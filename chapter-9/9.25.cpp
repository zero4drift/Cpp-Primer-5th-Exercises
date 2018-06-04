// c.erase(elem1, elem2)
// if elem1 and elem2 ponits to same element, the iterator range is empty, so erase nothing, return this elem1(or elem2, no matter, identical)
// if elem2 is a end off iterator, remove the one pointed by elem1 and till the last one, return elem2
// if elem1 and elem2 both end off iterator, remove nothing, return end off iterator

#include <list>
#include <iostream>

using std::list;
using std::cout;
using std::endl;

int main()
{
  list<int> li = {0, 1, 2, 3, 4};
  auto iter1 = li.begin(), iter2 = iter1;
  auto iter = li.erase(iter1, iter2);
  cout << *iter << endl;
  auto iter3 = li.end(), iter4 = iter3;
  iter = li.erase(iter3, iter4);
  cout << *iter << endl;	// the result is 5, there is no 5 in li, this operation is illegal
  // iter is the end off iterator
}
