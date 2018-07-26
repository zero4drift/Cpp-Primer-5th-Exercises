#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using std::regex;
using std::sregex_iterator;
using std::string;
using std::vector;
using std::count;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  vector<string> legal = {"albeit", "neighbor"};
  string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
  regex r(pattern, regex::icase);
  string sample, word;
  while(cin >> word)
    sample += (word + " ");
  sregex_iterator it(sample.begin(), sample.end(), r), end_it;
  cout << "Illegal words: " << endl;
  while(it != end_it)
    {
      if(count(legal.begin(), legal.end(), it->str()) == 0)
	  cout << it->str() << endl;
      ++it;
    }
}
