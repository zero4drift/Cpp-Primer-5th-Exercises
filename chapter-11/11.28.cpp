#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;

int main()
{
  map<string, vector<int>> m;
  map<string, vector<int>>::iterator iter = m.find("exist");
}
