#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

int main()
{
  int ia[] = {0, 1, 2, 3, 4, 5};
  vector<int> v(begin(ia), end(ia));
  for(auto i : v)
    cout << i << endl;
}
