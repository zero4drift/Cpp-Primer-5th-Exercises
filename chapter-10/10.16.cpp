#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::sort;
using std::find_if;
using std::unique;
using std::stable_sort;
using std::for_each;

void elimDups(vector<string> &words)
{
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
  elimDups(words);
  stable_sort(words.begin(), words.end(),
	      [](const string &word1, const string &word2)
	      {return word1.size() < word2.size();});
  auto iter = find_if(words.begin(), words.end(),
		      [sz](const string &word)
		      {return word.size() >= sz;});
  auto count = words.end() - iter;
  cout << count << " words" << endl;
  for_each(iter, words.end(), [](const string &s){cout << s << endl;});
}

int main()
{
  vector<string> vs =
    {"the", "time", "is", "near", "near", "the", "sunrise"};
  biggies(vs, 4);
}
