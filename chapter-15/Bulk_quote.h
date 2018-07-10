#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H


#include <string>
#include "Quote.h"

using std::string;
using std::size_t;

class Bulk_quote: public Quote
{
 public:
  using Quote::Quote;
 Bulk_quote(): Quote() {cout << "Bulk_quote()" << endl;};
 Bulk_quote(const Bulk_quote &b): Quote(b), min_qty(b.min_qty), discount(b.discount)
    {cout << "Bulk_Quote(const Bulk_quote &)" << endl;}
 Bulk_quote(Bulk_quote &&b): Quote(std::move(b)), min_qty(b.min_qty), discount(b.discount)
    {cout << "Bulk_quote(Bulk_quote &&b)" << endl;}
  Bulk_quote &operator=(const Bulk_quote &b)
    {
      Quote::operator=(b);
      min_qty = b.min_qty;
      discount = b.discount;
      {cout << "operator=(const Bulk_quote &)" << endl;} 
      return *this;
    }
  Bulk_quote &operator=(Bulk_quote &&b)
    {
      Quote::operator=(std::move(b));
      min_qty = b.min_qty;
      discount = b.discount;
      {cout << "operator=(Bulk_quote &&)" << endl;} 
      return *this;
    }
 Bulk_quote(const string & book, double p, size_t qty, double disc):
  Quote(book, p), min_qty(qty), discount(disc) {}
  double net_price(size_t) const override;
  ostream &debug() const override;
  Bulk_quote *clone() const & override {return new Bulk_quote(*this);}
  Bulk_quote *clone() && override {return new Bulk_quote(std::move(*this));}
  ~Bulk_quote() override {cout << "~Bulk_quote()" << endl;}
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

ostream &Bulk_quote::debug() const
{
  Quote::debug();
  cout << " min_qty " << min_qty << " discount " << discount;
  return cout;
}


#endif
