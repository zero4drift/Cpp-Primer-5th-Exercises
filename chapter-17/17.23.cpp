#include <regex>
#include <string>
#include <iostream>

using std::regex;
using std::smatch;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::sregex_iterator;

bool valid(const smatch& m)
{
  if(m[2].matched)
    {
      return m[3].matched;
    }
  return true;
}

int main()
{
  string postcode = "(\\d{5})([-])?(\\d{4})?";
  regex r(postcode);
  string s;
  while(getline(cin, s))
    {
      for(sregex_iterator it(s.begin(), s.end(), r), end_it;
	  it != end_it; ++it)
	if(valid(*it))
	  cout << "valid: " << it->str() << endl;
	else
	  cout << "not valid: " << it->str() << endl;
    }
}
