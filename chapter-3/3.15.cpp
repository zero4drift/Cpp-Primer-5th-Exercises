#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::vector;
using std::string;

int main()
{
  string s;
  vector<string> v;
  while(getline(cin, s))
    v.push_back(s);
}
