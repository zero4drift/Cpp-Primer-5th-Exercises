#include <map>
#include <string>
#include <vector>
#include <iostream>

using std::map;
using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
  map<string, vector<string>> family;
  family["Johnson"] = vector<string>{"Tom", "jack", "Lily"};
  family["Johnson"].push_back("Joe");
  for(const auto &p : family)
    {
      cout << "Family " << p.first
	   << " Children's names " << endl;
      for(const auto &s : p.second) cout << s << " ";
      cout << endl;
    }
}
