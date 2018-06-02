#include <string>
#include <iostream>

using std::string;
using std::cin;

int main()
{
  string s;
  char c;
  s.reserve(100);
  while(cin >> c)
    s.push_back(c);
}
