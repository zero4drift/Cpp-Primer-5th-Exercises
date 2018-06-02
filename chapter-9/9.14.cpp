#include <list>
#include <vector>
#include <string>

using std::list;
using std::vector;
using std::string;

int main()
{
  list<const char *> lst_c = {"hello", "world"};
  vector<string> vec_s;
  vec_s.assign(lst_c.begin(), lst_c.end());
}
