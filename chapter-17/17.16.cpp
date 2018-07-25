// Still able to find out the illegal word;
// but this version would just match the three-character part of a word, but not the whole word.

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
  regex r("[^c]ei");
  smatch results;
  string test;
  while(cin >> test)
    (regex_search(test, results, r))
      ? cout << results.str() << " illegal" << endl
      : cout << test << " legal" << endl;
}
