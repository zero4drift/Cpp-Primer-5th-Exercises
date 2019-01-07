#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

struct Sales_data;
istream &read(istream &is, Sales_data &item);
ostream &print(ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &item1, const Sales_data &item2);

struct Sales_data {
  friend istream &read(istream &, Sales_data &); 
  friend ostream &print(ostream &, const Sales_data &);
  friend Sales_data add(const Sales_data &item1, const Sales_data &item2);
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
  friend istream &operator>>(istream &, Sales_data &);
  friend ostream &operator<<(ostream &, const Sales_data &);
  friend bool operator==(const Sales_data &, const Sales_data &);
  friend bool operator!=(const Sales_data &, const Sales_data &);
  friend Sales_data operator-(const Sales_data &, const Sales_data &);
public:
  // Sales_data(): bookNo(""), units_sold(0), revenue(0) {}
  // Exercise 7.14 above has misleading due to the CN version.
  // It's ok to use the in-class initializer values.
Sales_data(): Sales_data("", 0, 0)
  {cout << " Default";};
Sales_data(const string &s): Sales_data(s, 0, 0)
  {cout << " With string argument";}
Sales_data(const string &s, unsigned n, double p):
  bookNo(s), units_sold(n), revenue(p*n)
  {cout << " With three arguments";}
Sales_data(istream &is): Sales_data()
  {cout << " With istream argument"; read(is, *this);}
  string isbn() const {return bookNo;}
  Sales_data& combine(const Sales_data&);
  Sales_data &operator+=(const Sales_data &);
  Sales_data &operator-=(const Sales_data &);
  Sales_data &operator=(const string &);
  operator string() const {return bookNo;}
  operator double() const {return revenue;}
private:
  double avg_price() const;
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};


#endif
