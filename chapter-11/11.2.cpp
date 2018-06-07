#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <set>

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::deque;
using std::map;
using std::set;

int main()
{
  // list: insert an element into a position which is not head or back. 
  list<int> li = {1, 2, 3, 4, 5, 6, 7, 8};
  li.insert(++li.begin(), 3);
  cout << "\nlist" << endl;
  for(const auto &i : li) cout << i << endl;
  // vector: random access
  vector<int> vi(li.cbegin(), li.cend());
  cout << "\nvector" << endl;
  cout << vi[4] << endl;
  // deque, insert or remove elements at head or back
  deque<int> di(li.cbegin(), li.cend());
  di.push_back(9);
  cout << "\ndeque" << endl;
  for(const auto &i : di) cout << i << endl;
  // map, associated key-value pair
  map<string, int> alphabegical;
  alphabegical["a"] = 1;
  alphabegical["b"] = 2;
  cout << "\nmap" << endl;
  for(const auto &w : alphabegical)
    cout << w.first << " " << w.second << endl;
  // set, filter keywords
  set<string> ss = {"fuck", "shit", "asshole", "bullshit"};
  cout << "\nset" << endl;
  for(const auto &s : ss) cout << s << endl;
}
