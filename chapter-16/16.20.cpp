#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::ostream;

template <typename T> ostream &print_container(const T &c)
{
  for(typename T::const_iterator beg = c.begin(); beg != c.end(); ++beg)
    cout << *beg << " ";
  return cout;
}

int main()
{
  vector<int> vi = {1, 2, 3};
  print_container(vi) << endl;
}
