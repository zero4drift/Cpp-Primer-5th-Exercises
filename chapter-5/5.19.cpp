#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  do
    {
      cout << "Please enter two strings: ";
      string s1, s2;
      cin >> s1 >> s2;
      cout << "Shorter one: " << (s1.size() >= s2.size() ? s2 : s1) << endl;
    }
  while(cin);
}
