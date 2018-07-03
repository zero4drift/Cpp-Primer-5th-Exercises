#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::sort;
using std::partition;
using std::unique;
using std::stable_sort;
using std::for_each;

class SizeSmaller
{
public:
  bool operator()(const string &w1, const string &w2) const
  {return w1.size() < w2.size();}
};

class SizeGE
{
  size_t sz;
public:
  SizeGE(size_t n): sz(n) {}
  bool operator()(const string &word) const
  {return word.size() >= sz;}
};

class PrintString
{
  ostream &o;
public:
  PrintString(ostream &os = cout): o(os) {}
  void operator()(const string &s) const
  {o << s;}
};

void elimDups(vector<string> &words)
{
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
  elimDups(words);
  stable_sort(words.begin(), words.end(), SizeSmaller());
  auto iter = partition(words.begin(), words.end(), SizeGE(sz));
  auto count = iter - words.begin();
  cout << count << " words" << endl;
  for_each(words.begin(), iter, PrintString());
}

int main()
{
  vector<string> vs =
    {"the", "time", "is", "near", "near", "the", "sunrise"};
  biggies(vs, 4);
}
