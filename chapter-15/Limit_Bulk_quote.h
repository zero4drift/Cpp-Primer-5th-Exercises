#ifndef LIMIT_BULK_QUOTE_H
#define LIMIT_BULK_QUOTE_H


#include <string>
#include "Quote.h"

using std::string;
using std::size_t;

class Limit_Bulk_quote: public Quote
{
 public:
  Limit_Bulk_quote() = default;
 Limit_Bulk_quote(const string & book, double p, size_t qty, size_t l, double disc):
  Quote(book, p), min_qty(qty), limit(l), discount(disc) {}
  double net_price(size_t) const override;
 private:
  size_t min_qty = 0;
  size_t limit = 0;
  double discount = 0.0;
};

double Limit_Bulk_quote::net_price(size_t cnt) const
{
  if(cnt >= min_qty and cnt <= limit)
    return cnt * (1 - discount) * price;
  else if(cnt >= min_qty and cnt > limit)
    return min_qty * (1 - discount) * price + (cnt - limit) * price;
  else
    return cnt * price;
}


#endif
