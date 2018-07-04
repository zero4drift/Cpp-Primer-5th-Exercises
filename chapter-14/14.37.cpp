#include <algorithm>
#include <vector>
#include <iostream>

using std::replace_if;
using std::vector;
using std::cout;
using std::endl;

class Equal
{
  int base = 0;
public:
  Equal() = default;
  Equal(int i): base(i) {};
  bool operator()(int i);
};

bool Equal::operator()(int i)
{
  return i == base;
}

int main()
{
  Equal eq(3);
  vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  replace_if(vi.begin(), vi.end(), eq, 4);
  for(const auto &i : vi)
    cout << i << endl;
}
