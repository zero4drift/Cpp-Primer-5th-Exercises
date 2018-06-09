#include <map>
#include <string>
#include <iostream>

using std::multimap;
using std::string;
using std::cout;
using std::endl;

void print_author(multimap<string, string> &authors, string author)
{
  cout << author << ": ";
  auto range = authors.equal_range(author);
  for(auto beg = range.first;
      beg != range.second; ++beg)
    cout << beg->second << ", ";
  cout << endl;
}

int main()
{
  multimap<string, string> authors =
    {{"tom", "abc"},
     {"tom", "bde"},
     {"jack", "cde"},
     {"levis", "ddd"},
     {"jane", "eee"}};
  print_author(authors, "tom");
}
