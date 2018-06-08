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
  pair<string, int> p;
  vector<pair<string, int>> vp;
  auto vs_begin = vs.cbegin();
  auto vi_begin = vi.cbegin();
  while(vs_begin != vs.end() && vi_begin != vi.end())
    {
      p.first = *vs_begin;
      p.second = *vi_begin;
      vp.push_back(p);
      ++vs_begin;
      ++vi_begin;
    }
  for(const auto &p : vp)
    cout << "First " << p.first << " second " << p.second << endl;
}
