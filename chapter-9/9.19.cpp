#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
  string s;
  list<string> ds;
  while(cin >> s)
    ds.push_back(s);
  list<string>::iterator bit = ds.begin(), eit = ds.end();
  while(bit != eit)
    {
      cout << *bit << endl;
      ++bit;
    }
}
