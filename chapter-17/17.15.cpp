#include <regex>
#include <string>
#include <iostream>

using std::regex;
using std::smatch;
using std::regex_search;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
  regex r(pattern);
  smatch results;
  string test;
  while(cin >> test)
    (regex_search(test, results, r))
      ? cout << test << " illegal" << endl
      : cout << test << " legal" << endl;
}
