#include <vector>
#include <string>
#include <algorithm>
#include "Sales_data.h"

using std::vector;
using std::string;
using std::equal_range;

class Matches
{
public:
  using s = vector<Sales_data>::size_type;
  using c = vector<Sales_data>::const_iterator;
  Matches() = default;
  Matches(s i, c it1, c it2): index(i), first(it1), last(it2) {}
private:
  s index;
  c first;
  c last;
};

bool compareIsbn(const Sales_data &d1, const Sales_data &d2)
{
  return d1.isbn() < d2.isbn();
}

vector<Matches>
findBllk(const vector<vector<Sales_data>> &files,
	 const string &book)
{
  vector<Matches> ret;
  for(auto it = files.cbegin(); it != files.cend(); ++it)
    {
      auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
      if(found.first != found.second)
	ret.push_back(Matches(it - files.cbegin(),
				 found.first, found.second));
    }
  return ret;
}
