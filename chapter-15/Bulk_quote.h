#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H


#include <string>
#include "Quote.h"

using std::string;
using std::size_t;

class Bulk_quote: public Quote
{
 public:
  Bulk_quote() = default;
 Bulk_quote(const string & book, double p, size_t qty, double disc):
  Quote(book, p), min_qty(qty), discount(disc) {}
  double net_price(size_t) const override;
 private:
  size_t min_qty = 0;
  double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const
{
  if(cnt >= min_qty)
    return cnt * (1 - discount) * price;
  else
    return cnt * price;
}


#endif
