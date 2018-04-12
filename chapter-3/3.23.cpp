#include <vector>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
  int i, cnt = 0;
  vector<int> v;
  while(cnt != 10 && cin >> i)
    {
      v.push_back(i);
      ++cnt;
    }
  for(auto it = v.begin(); it != v.end(); ++it)
    {
      *it = 2 * (*it);
      cout << *it << endl;
    }
}
