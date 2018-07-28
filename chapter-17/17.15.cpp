#include <regex>
#include <string>
#include <iostream>

using std::regex;
using std::smatch;
using std::regex_match;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);
  regex r(pattern);
  smatch results;
  string test;
  while(cin >> test)
    (regex_match(test, results, r))
      ? cout << test << " illegal" << endl
      : cout << test << " legal" << endl;
}
