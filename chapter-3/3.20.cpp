#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
  int i;
  vector<int> v;
  while(cin >> i)
    v.push_back(i);
  for(decltype(v.size()) index = 0; index != v.size(); ++index)
    if((index + 1) < v.size())
      cout << v[index] + v[index + 1] << endl;
  for(decltype(v.size()) index = 0; index != (v.size() / 2) + 1; ++index)
    if((v.size() - 1 - index) >= index)
      cout << v[index] + v[v.size() - 1 - index] << endl;
}
