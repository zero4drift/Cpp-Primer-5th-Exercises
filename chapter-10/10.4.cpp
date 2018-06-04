#include <vector>
#include <numeric>
#include <iostream>

using std::vector;
using std::accumulate;
using std::cout;
using std::endl;

int main()
{
  vector<double> vi = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5};
  double sum = accumulate(vi.begin(), vi.end(), 0); // sum is 15.0
  // element in vi is transformmed to type int, precision loss
  // that is not good
  cout << sum << endl;
}
