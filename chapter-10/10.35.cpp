#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
  vector<int> vi = {1, 2, 3, 4, 5, 6, 7};
  for(auto iter = vi.cend() - 1; iter != vi.cbegin() - 1; --iter)
    cout << *iter << endl;
}
