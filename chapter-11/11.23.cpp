#include <map>
#include <string>
#include <iostream>

using std::multimap;
using std::string;
using std::cout;
using std::endl;

int main()
{
  multimap<string, string> family;
  // family.insert({{"Johnson", "Tom"}, {"Johnson", "Jack"}});
  family.insert({"Johnson", "Tom"});
  family.insert({"Johnson", "Jack"});
  family.insert({"Johnson", "Lily"});
  family.insert({"Johnson", "Joe"});
  for(const auto &p : family)
    {
      cout << "Family " << p.first
	   << " Children's names " << p.second << endl;
    }
}
