#include <string>
#include <vector>
#include <iostream>
#include <utility>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

int main()
{
  vector<string> vs = {"hello", "world"};
  vector<int> vi = {1, 2};
  vector<pair<string, int>> vp;
  pair<string, int> p;
  auto vs_begin = vs.cbegin();
  auto vi_begin = vi.cbegin();
  while(vs_begin != vs.end() && vi_begin != vi.end())
    {
      // first way is illustrated in 11.12.cpp
      // second way
      // p = make_pair(*vs_begin, *vi_begin); 
      // third way
      // p = {*vs_begin, *vi_begin};
      // fourth way: best
      // easier to write and understand
      vp.emplace_back(*vs_begin, *vi_begin);
      // vp.push_back(p);
      ++vs_begin;
      ++vi_begin;
    }
  for(const auto &p : vp)
    cout << "First " << p.first << " second " << p.second << endl;
}
