#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
  vector<int> vi = {1, 2, 3, 4, 5, 6, 7};
  for(auto riter = vi.crbegin(); riter != vi.crend(); ++riter)
    cout << *riter << endl;
}
