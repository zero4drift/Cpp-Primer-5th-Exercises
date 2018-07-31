#include "Sales_data.h"
#include "Sales_data_exception.h"

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
  if(is)
    item.revenue = price * item.units_sold;
  else
    item = Sales_data();
  return is;
}

istream &operator>>(istream &i, Sales_data &data)
{
  double price;
  i >> data.bookNo >> data.units_sold >> price;
  if(i)
    data.revenue = price * data.units_sold;
  else
    data = Sales_data();
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

Sales_data &Sales_data::operator+=(const Sales_data &data)
{
  if(isbn() != data.isbn())
    throw isbn_mismatch("wrong  isbns", isbn(), data.isbn());
  return combine(data);
}

Sales_data &Sales_data::operator-=(const Sales_data &data)
{
  units_sold -= data.units_sold;
  revenue -= data.revenue;
  return *this;
}

Sales_data &Sales_data::operator=(const string &s)
{
  bookNo = s;
  units_sold = 0;
  revenue = 0.0;
  return *this;
}

Sales_data operator+(const Sales_data &data1, const Sales_data &data2)
{
  Sales_data temp = data1;
  temp += data2;
  return temp;
}

Sales_data operator-(const Sales_data &data1, const Sales_data &data2)
{
  Sales_data temp = data1;
  temp -= data2;
  return temp;
}

bool operator==(const Sales_data &data1, const Sales_data &data2)
{
  return data1.bookNo == data2.bookNo &&
    data1.units_sold == data2.units_sold &&
    data1.revenue == data2.revenue;
}

bool operator!=(const Sales_data &data1, const Sales_data &data2)
{
  return !(data1 == data2);
}
