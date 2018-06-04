#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::sort;
using std::unique;

void elimDups(vector<string> &words)
{
  for(const auto &s : words) cout << s << endl;
  sort(words.begin(), words.end());
  for(const auto &s : words) cout << s << endl;
  auto end_unique = unique(words.begin(), words.end());
  for(const auto &s : words) cout << s << endl;
  words.erase(end_unique, words.end());
  for(const auto &s : words) cout << s << endl;
}

int main()
{
  vector<string> vs =
    {"the", "time", "is", "near", "near", "the", "sunrise"};
  elimDups(vs);
}
