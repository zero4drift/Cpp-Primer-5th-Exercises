#include <map>
#include <string>
#include <iostream>

using std::multimap;
using std::string;
using std::cout;
using std::endl;

void safe_erase(multimap<string, string> &authors, string author)
{
  multimap<string, string>::iterator iter;
  while((iter = authors.find(author)) != authors.end())
    authors.erase(iter);
}

int main()
{
  multimap<string, string> authors ={{"tom", "abc"}, {"tom", "ddd"}, {"jack", "cde"}, {"levis", "ddd"}, {"jane", "eee"}};
  safe_erase(authors, "tom");
  for(const auto &p : authors) cout << p.first << " " << p.second << endl;
}
