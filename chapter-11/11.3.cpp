#include <set>
#include <map>
#include <string>
#include <iostream>

using std::size_t;
using std::set;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  map<string, size_t> word_cound;
  set<string> exclude = {"The", "But", "And", "Or", "An", "A",
			 "the", "but", "and", "or", "an", "a"};
  string word;
  while(cin >> word)
    if(exclude.find(word) == exclude.end())
      ++word_cound[word];
  for(const auto &w : word_cound)
    cout << w.first << " occurs " << w.second
	 << ((w.second > 1) ? " times" : " time") << endl;
}
