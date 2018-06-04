#include <vector>
#include <numeric>
#include <iostream>

using std::vector;
using std::accumulate;
using std::cout;
using std::endl;

int main()
{
  vector<int> vi = {0, 1, 2, 3, 4, 5};
  int sum = accumulate(vi.begin(), vi.end(), 0);
  cout << sum << endl;
}
