#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;


struct Sales_data;

istream &read(istream &is, Sales_data &item);

ostream &print(ostream &os, const Sales_data &item);

Sales_data add(const Sales_data &item1, const Sales_data &item2);

struct Sales_data {
  // Sales_data(): bookNo(""), units_sold(0), revenue(0) {};
  // Exercise 7.14 above has misleading due to the CN version.
  // It's ok to use the in-class initializer values.
  Sales_data() = default;
Sales_data(const string &s): bookNo(s) {}
Sales_data(const string &s, unsigned n, double p):
  bookNo(s), units_sold(n), revenue(p*n) {}
  Sales_data(istream &is) {read(is, *this);}
  string isbn() const {return bookNo;}
  Sales_data& combine(const Sales_data&);
  double avg_price() const;
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

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

#endif
