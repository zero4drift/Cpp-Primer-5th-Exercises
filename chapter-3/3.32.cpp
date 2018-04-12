#include <cstddef>
#include <vector>
#include <iostream>

using std::vector;
using std::size_t;
using std::cout;
using std::endl;

int main()
{
  // array version
  int ia[10];
  int ib[10];
  for(size_t i = 0; i < 10; ++i)
    ia[i] = i;			// size_t type object could be implicitly converted to int type
  for(size_t i = 0; i < 10; ++i)
    ib[i] = ia[i];
  for(auto i : ib)
    cout << i << endl;
  // vector version
  vector<int> va(10);
  vector<int> vb(10);
  for(auto i = va.begin(); i != va.end(); ++i)
    *i = (i - va.begin());
  vb = va;
  for(auto i : vb)
    cout << i << endl;
}
