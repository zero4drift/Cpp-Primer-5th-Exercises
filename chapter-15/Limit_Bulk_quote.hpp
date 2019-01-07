#ifndef LIMIT_BULK_QUOTE_H
#define LIMIT_BULK_QUOTE_H


#include <string>
#include "Quote.hpp"

using std::string;
using std::size_t;

class Limit_Bulk_quote: public Quote
{
 public:
  Limit_Bulk_quote() = default;
 Limit_Bulk_quote(const string & book, double p, size_t qty, double disc):
  Quote(book, p), max_qty(qty), discount(disc) {}
  double net_price(size_t) const override;
  ostream &debug() const override;
 private:
  size_t max_qty = 0;
  double discount = 0.0;
};

double Limit_Bulk_quote::net_price(size_t cnt) const
{
  if(cnt <= max_qty)
    return cnt * (1 - discount) * price;
  else
    return max_qty * (1 - discount) * price + (cnt - max_qty) * price;
}

ostream &Limit_Bulk_quote::debug() const
{
  Quote::debug();
  cout << " max_qty " << max_qty << " discount " << discount;
  return cout;
}


#endif
