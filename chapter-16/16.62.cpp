#include <unordered_set>
#include <iostream>
#include "Sales_data.hpp"

using std::unordered_multiset;
using std::cout;
using std::endl;

int main()
{
  unordered_multiset<Sales_data> ums;
  ums.insert(Sales_data());
  ums.insert(Sales_data("1234", 23, 10.1));
  for(auto iter = ums.cbegin(); iter != ums.cend(); ++iter)
    cout << *iter << endl;
}
