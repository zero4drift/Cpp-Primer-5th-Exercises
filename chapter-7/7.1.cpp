#include <iostream>
#include "Sales_data.h"

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
