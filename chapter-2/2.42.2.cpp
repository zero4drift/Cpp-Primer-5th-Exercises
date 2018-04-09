#include <iostream>
#include "Sales_data.h"

int main()
{
  unsigned sold_sum = 0;
  double revenue_sum = 0.0;
  Sales_data item;
  while(std::cin >> item.bookNo >> item.units_sold >> item.revenue)
    {
      sold_sum += item.units_sold;
      revenue_sum += item.revenue;
    }
  std::cout << item.bookNo << " "
	    << sold_sum << " "
	    << revenue_sum << std::endl;
  return 0;
}
