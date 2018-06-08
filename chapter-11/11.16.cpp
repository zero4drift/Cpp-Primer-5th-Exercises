#include <map>
#include <iostream>

using std::map;
using std::cout;
using std::endl;

int main()
{
  map<int, int> sample = {{1, 2}};
  auto beg = sample.begin();
  cout << beg->first << " " << beg->second << endl;
  beg->second = 3;
  cout << beg->first << " " << beg->second << endl;
}
