#include <iostream>
#include "Sales_data.h"

int main()
{
  Sales_data item1, item2;
  std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue
	   >> item2.bookNo >> item2.units_sold >> item2.revenue;
  std::cout << item1.bookNo << " "
	    << item1.units_sold + item2.units_sold << " "
	    << item1.revenue + item2.revenue << std::endl;
  return 0;
}
