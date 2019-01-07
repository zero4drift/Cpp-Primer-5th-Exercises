#include <iostream>
#include <algorithm>
#include <vector>
#include "Sales_data.hpp"

using std::sort;
using std::vector;
using std::cin;

bool compareIsbn(Sales_data &d1, Sales_data &d2)
{
  return d1.isbn() < d2.isbn();
}

int main()
{
  vector<Sales_data> vs;
  while(cin)
    {
      Sales_data item;
      read(cin,item);
      vs.push_back(item);
    }
  sort(vs.begin(), vs.end(), compareIsbn);
}
