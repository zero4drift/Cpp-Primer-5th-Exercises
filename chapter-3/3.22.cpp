#include <cctype>
#include <vector>
#include <string>
#include <iostream>

using std::toupper;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
  vector<string> vs;
  string s;
  while(getline(cin, s))
    vs.push_back(s);
  for(auto it = vs.begin(); it != vs.end() && !it->empty(); ++it)
    {
      for(auto it2 = it->begin(); it2 != it->end(); ++it2)
	*it2 = toupper(*it2);
      cout << *it << endl;
    }
}
