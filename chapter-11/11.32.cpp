#include <map>
#include <set>
#include <string>
#include <iostream>

using std::map;
using std::multimap;
using std::multiset;
using std::string;
using std::cout;
using std::endl;

int main()
{
  multimap<string, string> authors =
    {{"tom", "abc"},
     {"tom", "bde"},
     {"jack", "cde"},
     {"levis", "ddd"},
     {"jane", "eee"}};
  map<string, multiset<string>> order_authors;
  for(const auto &author : authors)
    order_authors[author.first].insert(author.second);
  for(const auto &author : order_authors)
    {
      cout << author.first << ": ";
      for(const auto &work : author.second)
	cout << work << " ";
      cout << endl;
    }
}
