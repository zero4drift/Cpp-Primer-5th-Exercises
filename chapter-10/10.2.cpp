#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::string;
using std::count;

int main()
{
  string i;
  list<string> ls;
  while(cin >> i)
    ls.push_back(i);
  cout << "Specify a string: " << endl;
  cin.clear();
  cin >> i;
  cout << "There are " << count(ls.begin(), ls.end(), i)
       << " count of " << i << " in input strings" << endl;
}
