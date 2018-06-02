#include <iostream>
#include <deque>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::string;

int main()
{
  string s;
  deque<string> ds;
  while(cin >> s)
    ds.push_back(s);
  deque<string>::iterator bit = ds.begin(), eit = ds.end();
  while(bit != eit)
    {
      cout << *bit << endl;
      ++bit;
    }
}
