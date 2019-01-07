#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Sales_data.hpp"

using std::mem_fn;
using std::vector;
using std::string;
using std::find_if;
using std::cout;
using std::endl;

const Sales_data &find_ge_price(const vector<Sales_data> &vs, double price)
{
  auto f = mem_fn(&Sales_data::avg_price);
  return *(find_if(vs.cbegin(), vs.cend(),
		   [&f, price] (const Sales_data &s) {return f(s) > price;}));
}

int main()
{
  vector<Sales_data> vs = {
    Sales_data("123", 12, 21),
    Sales_data("456", 13, 22)};
  cout << find_ge_price(vs, 21) << endl;
}
