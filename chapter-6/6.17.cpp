#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool any_uppercase(const string& s)
{
  bool upper = false;
  for(char c : s)
    if(isupper(c))
      {
	upper = true; 
	break;
      }
  return upper;
}

void lower_string(string& s)
{
  for(char& c : s)
    c = tolower(c);
}

int main()
{
  cout << "Enter a string: ";
  string s;
  cin >> s;
  bool any_upper = any_uppercase(s);
  lower_string(s);
  cout << "The input string " << any_upper << " uppercase "
       << "after transform " << s << endl;
}
