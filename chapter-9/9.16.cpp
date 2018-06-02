#include <vector>
#include <list>

using std::vector;
using std::list;

bool is_equal_iv_il(vector<int> iv, list<int> il)
{
  vector<int> iv2(il.begin(), il.end());
  return iv == iv2;
}
