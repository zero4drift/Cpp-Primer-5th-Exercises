#ifndef LIMIT_BULK_QUOTE_H
#define LIMIT_BULK_QUOTE_H


#include <string>
#include "Disc_quote.h"

using std::string;
using std::size_t;

class Limit_Bulk_quote: public Disc_quote
{
 public:
  Limit_Bulk_quote() = default;
 Limit_Bulk_quote(const string & book, double p, size_t qty, double disc):
  Disc_quote(book, p, qty, disc) {}
  double net_price(size_t) const override;
  ostream &debug() const override;
};

double Limit_Bulk_quote::net_price(size_t cnt) const
{
  if(cnt <= quantity)
    return cnt * (1 - discount) * price;
  else
    return quantity * (1 - discount) * price + (cnt - quantity) * price;
}

ostream &Limit_Bulk_quote::debug() const
{
  Quote::debug();
  cout << " max_qty " << quantity << " discount " << discount;
  return cout;
}


#endif
