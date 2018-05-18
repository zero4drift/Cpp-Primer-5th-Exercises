#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::istream;

class Sales_data;
istream &read(istream &, Sales_data &);

class Sales_data
{
  friend istream &read(istream &, Sales_data &);
public:
  Sales_data(istream &is = cin) {read(is, *this);}
private:
  string bookNo;
  int units_sold = 0;
  double revenue = 0.0;
};

istream &read(istream &is, Sales_data &item)
{
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}
