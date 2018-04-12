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
  int i;
  vector<int> v;
  while(cin >> i)
    v.push_back(i);
  for(auto it = v.begin(); it != v.end(); ++it)
    {
      if((it + 1) != v.end())
	cout << *it + *(it+1) << endl;
    }
  auto mid = v.begin() + v.size() / 2;
  for(auto it = v.begin(); it <= mid; ++it)
    {
      if(it <= (v.end() - (it - v.begin()) - 1))
	cout << *it + *(v.end() - (it - v.begin()) - 1) << endl;
    }
}
