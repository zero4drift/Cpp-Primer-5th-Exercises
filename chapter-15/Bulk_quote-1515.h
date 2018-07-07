#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H


#include <string>
#include "Disc_quote.h"

using std::string;
using std::size_t;

class Bulk_quote: public Disc_quote
{
 public:
  Bulk_quote() = default;
 Bulk_quote(const string & book, double p, size_t qty, double disc):
  Disc_quote(book, p, qty, disc) {}
  double net_price(size_t) const override;
  ostream &debug() const override;
};

double Bulk_quote::net_price(size_t cnt) const
{
  if(cnt >= quantity)
    return cnt * (1 - discount) * price;
  else
    return cnt * price;
}

ostream &Bulk_quote::debug() const
{
  Quote::debug();
  cout << " min_qty " << quantity << " discount " << discount;
  return cout;
}


#endif
