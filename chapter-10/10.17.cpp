#include <iostream>
#include <algorithm>
#include <vector>
#include "Sales_data.h"

using std::sort;
using std::vector;
using std::cin;

int main()
{
  vector<Sales_data> vs;
  while(cin)
    {
      Sales_data item;
      read(cin,item);
      vs.push_back(item);
    }
  sort(vs.begin(), vs.end(),
       [](Sales_data &item1, Sales_data &item2)
       {return item1.isbn() < item2.isbn();});
}
