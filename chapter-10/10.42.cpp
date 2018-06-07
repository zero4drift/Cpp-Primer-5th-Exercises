#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using std::list;
using std::string;
using std::cout;
using std::endl;
using std::sort;
using std::unique;

void elimDups(list<string> &words)
{
  words.sort();
  words.unique();
}

int main()
{
  list<string> ls =
    {"the", "time", "is", "near", "near", "the", "sunrise"};
  elimDups(ls);
  for(const auto &s : ls) cout << s << endl;
}
