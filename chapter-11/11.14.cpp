#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <utility>

using std::map;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::pair;

int main()
{
  map<string, vector<pair<string, unsigned>>> family;
  family["Johnson"] = vector<pair<string, unsigned>>
    {{"Tom", 19990712},
     {"jack", 20040918},
     {"Lily", 20061123}};
  family["Johnson"].emplace_back("Joe", 20100830);
  for(const auto &p : family)
    {
      cout << "Family " << p.first
	   << " Children's names " << endl;
      for(const auto &p2 : p.second)
	cout << p2.first << " birthday " << p2.second << endl;
    }
}
