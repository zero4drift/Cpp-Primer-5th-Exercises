#include <vector>
#include <memory>
#include <iostream>
#include "Quote.hpp"
#include "Bulk_quote.hpp"

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

int main()
{
  vector<Quote> basket1;
  basket1.push_back(Bulk_quote("123", 50, 10, 0.10));
  basket1.push_back(Bulk_quote("234", 60, 15, 0.15));
  double total = 0.0;
  for(const auto &p : basket1)
    total += p.net_price(20);
  cout << total << endl;
  cout << string("=", 15) << endl;
  vector<shared_ptr<Quote>> basket2;
  basket2.push_back(make_shared<Bulk_quote>("123", 50, 10, 0.10));
  basket2.push_back(make_shared<Bulk_quote>("234", 60, 15, 0.15));
  total = 0.0;
  for(const auto &p : basket2)
    total += p->net_price(20);
  cout << total << endl;
}
