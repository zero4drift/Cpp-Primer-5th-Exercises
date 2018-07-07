#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_Bulk_quote.h"

int main()
{
  Quote a("123", 21.1);
  Bulk_quote b("123", 21.1, 5, 0.05);
  Limit_Bulk_quote c("123", 21.1, 5, 0.05);
  print_total(std::cout, a, 5);
  a.debug() << endl;
  print_total(std::cout, b, 5);
  b.debug() << endl;
  print_total(std::cout, c, 6);
  c.debug() << endl;
}
