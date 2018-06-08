#include <set>
#include "Sales_data.h"

using std::multiset;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
  return lhs.isbn()f < rhs.isbn();
}

int main()
{
  multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookstore(compareIsbn);
}
