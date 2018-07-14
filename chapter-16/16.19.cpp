#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::ostream;

template <typename T> ostream &print_container(const T &c)
{
  for(typename T::size_type i = 0; i != c.size(); ++i)
    cout << c[i] << " ";
  return cout;
}

int main()
{
  vector<int> vi = {1, 2, 3};
  print_container(vi) << endl;
}
