// As the operator+= and operator+ member functions defined within class Sales_data;
// if the third argument of accumulate function is Sales_data(), the return result as a Sales_data object whose bookNo is an empty string.

#include <tuple>
#include <iostream>
#include <vector>
#include <numeric>
#include "Sales_data.h"

using std::tuple;
using std::get;
using std::istream;
using std::cin;
using std::cout;
using std::ostream;
using std::vector;
using std::accumulate;

using matches = tuple<vector<Sales_data>::size_type,
		      vector<Sales_data>::const_iterator,
		      vector<Sales_data>::const_iterator>;

extern vector<matches> findBook(const vector<vector<Sales_data>> &files,
				const string &book);

void reportResults(istream &in, ostream &os,
		   const vector<vector<Sales_data>> &files)
{
  string s;
  while(in >> s)
    {
      auto trans = findBook(files, s);
      if(trans.empty())
	{
	  cout << s << " not found in any stores" << endl;
	  continue;
	}
      for(const auto &store : trans)
	os << "store " << get<0>(store) << " sales: "
	   << accumulate(get<1>(store), get<2>(store), Sales_data())
	   << endl;
    }
}

int main()
{
  vector<vector<Sales_data>> total;
  vector<Sales_data> store1 = {Sales_data("1", 12, 2), Sales_data("1", 23, 2)};
  total.push_back(store1);
  reportResults(cin, cout, total);
}
