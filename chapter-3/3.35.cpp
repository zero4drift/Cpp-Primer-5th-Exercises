#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
  int ia[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *pbeg = begin(ia), *pend = end(ia);
  while(pbeg != pend)
    {
      *pbeg = 0;
      ++pbeg;
    }
  for(auto i : ia)
    cout << i << endl;
}
