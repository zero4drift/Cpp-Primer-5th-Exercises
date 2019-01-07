#include <iostream>
#include <string>
#include "Sales_data.hpp"

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

int main()
{
  int cnt = 1;
  Sales_data item1, item2;
  if(std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue)
    {
      while(std::cin >> item2.bookNo >> item2.units_sold >> item2.revenue)
	{
	  // don't worry, Sales_item item is initialized when created
	  if(item1.bookNo == item2.bookNo)
	    cnt += 1;
	  else
	    {
	      std::cout << item1.bookNo << " recorded " << cnt << std::endl;
	      item1 = item2;
	      cnt = 1;
	    }
	}
      // the last one
      std::cout << item1.bookNo << " recorded " << cnt << std::endl;
    }
  else
    {
      std::cerr << "No data?" << std::endl;
      return -1;
    }
  return 0;
}
