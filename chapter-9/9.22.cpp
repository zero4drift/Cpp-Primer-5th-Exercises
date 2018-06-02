// Changing the size of vector type object may cause re-allocation of its memory space.
// the iterator iter and mid in original program may be invalid when program processing

#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
  vector<int> iv = {1, 2, 2, 4, 2, 6, 2, 3, 4, 5};
  list<int> il(iv.begin(), iv.end());
  list<int>::iterator iter = il.begin();
  vector<int>::difference_type count = 0, dff_iv = iv.size() / 2;
  while(count != dff_iv)
    {
      if(*iter == 2)
	il.insert(iter, 2 * 2);
      ++count;
      ++iter;
    }
  iv.assign(il.begin(), il.end());
  for(const auto &i : iv)
    cout << i << endl;
}
