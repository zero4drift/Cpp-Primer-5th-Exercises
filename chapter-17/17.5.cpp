#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include "Sales_data.hpp"

using std::vector;
using std::pair;
using std::make_pair;
using std::string;
using std::equal_range;
using matches = pair<vector<Sales_data>::size_type,
		     pair<vector<Sales_data>::const_iterator,
			  vector<Sales_data>::const_iterator>>;

bool compareIsbn(const Sales_data &d1, const Sales_data &d2)
{
  return d1.isbn() < d2.isbn();
}

vector<matches>
findBllk(const vector<vector<Sales_data>> &files,
	 const string &book)
{
  vector<matches> ret;
  for(auto it = files.cbegin(); it != files.cend(); ++it)
    {
      auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
      if(found.first != found.second)
	ret.push_back(make_pair(it - files.cbegin(),
				make_pair(found.first, found.second)));
    }
  return ret;
}
