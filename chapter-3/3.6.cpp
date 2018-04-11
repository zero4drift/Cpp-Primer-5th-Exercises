#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string s;
  getline(cin, s);
  for(auto &c : s)
    c = 'X';
  cout << s << std::endl;
}
