#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

double Sales_data::avg_price() const
{
  if(units_sold)
    return revenue/units_sold;
  else
    return 0;
}

istream &read(istream &is, Sales_data &item)
{
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
  Sales_data result = item1;
  return result.combine(item2);
}
