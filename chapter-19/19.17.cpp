#include "Sales_data.hpp"

int main()
{
  using p1 = string (Sales_data::*)() const;
  using p2 = Sales_data &(Sales_data::*)(const Sales_data &);
  using p3 = Sales_data &(Sales_data::*)(const string &);
  using p4 = double (Sales_data::*)() const;
}
