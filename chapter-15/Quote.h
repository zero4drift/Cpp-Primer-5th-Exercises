#ifndef QUOTE_H
#define QUOTE_H


#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::size_t;

class Quote
{
public:
  Quote() {cout << "Quote()" << endl;}
  Quote(const string &book, double sales_price):
  bookNo(book), price(sales_price)
  {cout << "Quote(cosnt string &, double)" << endl;}
  string isbn() const {return bookNo;}
  Quote(const Quote &q)
    {bookNo = q.bookNo; price = q.price; cout << "Quote(const Quote &)" << endl;}
  Quote &operator=(const Quote &q)
    {
      bookNo = q.bookNo;
      price = q.price;
      cout << "Quote &operator=(const Quote &)" << endl;
      return *this;
    }
  Quote(Quote &&q)
    {bookNo = std::move(q.bookNo); price = q.price; cout << "Quote(Quote &&)" << endl;}
  Quote &operator=(Quote &&q)
    {
      bookNo = std::move(q.bookNo);
      price = q.price;
      cout << "Quote &operator=(Quote &&)" << endl;
      return *this;
    }
  virtual double net_price(size_t n) const
  {return n * price;}
  virtual ostream &debug() const
  {
    cout << "bookNo " << bookNo << " price " << price;
    return cout;
  }
  virtual ~Quote() {cout << "~Quote()" << endl;};
private:
  string bookNo;
protected:
  double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn()
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}


#endif
