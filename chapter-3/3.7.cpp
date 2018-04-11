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
  for(char &c : s)		// no difference from 3.6
    c = 'X';
  cout << s << std::endl;
}
