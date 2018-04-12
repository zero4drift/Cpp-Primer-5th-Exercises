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
  for(char c : s)		// c is a copy of character in string s
    c = 'X';
  cout << s << std::endl;	// actually s is unchanged
}
