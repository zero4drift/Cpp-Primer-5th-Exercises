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
using std::stable_sort;

bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

int main()
{
  vector<string> vs =
    {"the", "time", "is", "near", "near", "the", "great", "sunrise"};
  elimDups(vs);
  stable_sort(vs.begin(), vs.end(), isShorter);
  for(const auto &s : vs) cout << s << endl;
}
