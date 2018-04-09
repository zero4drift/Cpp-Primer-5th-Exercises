#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
  Sales_data item;
  while(std::cin >> item.bookNo >> item.units_sold >> item.revenue)
    {
      std::cout << item.bookNo << " "
		<< item.units_sold << " "
		<< item.revenue << std::endl;
    }
  return 0;
}
