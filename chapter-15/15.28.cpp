#include <vector>
#include <memory>
#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

int main()
{
  vector<shared_ptr<Quote>> basket;
  // basket.push_back(make_shared<Bulk_quote>("123", 50, 10, 0.10));
  // basket.push_back(make_shared<Bulk_quote>("234", 60, 15, 0.15));
  basket.push_back(make_shared<Quote>("123", 50));
  basket.push_back(make_shared<Quote>("234", 60));
  double total = 0.0;
  for(const auto &p : basket)
    total += p->net_price(20);
  cout << total << endl;
}
