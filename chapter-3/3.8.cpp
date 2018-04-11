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
  // decltype(s.size()) index = 0;
  // while(index != s.size())
  //   {
  //     s[index] = 'X';
  //     ++index;
  //   }
  for(decltype(s.size()) index = 0; index != s.size(); ++index)
    s[index] = 'X';		// using for is more user-friendly
  cout << s << std::endl;
}
