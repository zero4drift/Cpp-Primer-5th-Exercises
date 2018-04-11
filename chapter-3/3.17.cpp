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
  string s;
  vector<string> v;
  while(cin >> s)
    v.push_back(s);
  for(auto &ss : v)
    {
      for(auto &c : ss)
	c = toupper(c);
    }
  for(auto ss : v)
    cout << ss << endl;
}
