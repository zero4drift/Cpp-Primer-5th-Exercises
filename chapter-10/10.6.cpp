#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::fill_n;
using std::cout;
using std::endl;

int main()
{
  vector<int> vi = {1, 2, 3, 4, 5, 6};
  fill_n(vi.begin(), vi.size(), 0);
  for(const auto &i : vi)
    cout << i << endl;
}
