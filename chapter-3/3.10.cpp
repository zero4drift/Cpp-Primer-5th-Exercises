#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string s, result;
  getline(cin, s);
  for(auto c : s)
    {
      if(!ispunct(c)) result += c;
    }
  cout << result << std::endl;
}
