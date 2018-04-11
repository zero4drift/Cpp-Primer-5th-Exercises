#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string result, s;
  while(getline(cin, s))
    {
      result += s;
      result += " ";
    }
  cout << result;
}
