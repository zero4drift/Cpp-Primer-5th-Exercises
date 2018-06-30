#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

inline double Sales_data::avg_price() const
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

istream &operator>>(istream &i, Sales_data &data)
{
  double price;
  i >> data.bookNo >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  return i;
}

ostream &print(ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
  return os;
}

ostream &operator<<(ostream &o, const Sales_data &data)
{
  o << data.isbn() << " " << data.units_sold << " " << data.revenue << " " << data.avg_price();
  return o;
}

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
  Sales_data result = item1;
  return result.combine(item2);
}

Sales_data operator+(const Sales_data &data1, const Sales_data &data2)
{
  return Sales_data(data1.bookNo,
		    data1.units_sold + data2.units_sold,
		    data1.revenue + data2.revenue);
}

Sales_data &Sales_data::operator+=(const Sales_data &data)
{
  return combine(data);
}
