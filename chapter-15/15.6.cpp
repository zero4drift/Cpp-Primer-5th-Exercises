#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

int main()
{
  Quote a("123", 21.1);
  Bulk_quote b("123", 21.1, 5, 0.05);
  print_total(std::cout, a, 5);
  print_total(std::cout, b, 5);
}
