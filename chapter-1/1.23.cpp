#include <iostream>
#include "Sales_item.hpp"

int main()
{
  int cnt = 1;
  Sales_item item1, item2;
  if(std::cin >> item1)
    {
      while(std::cin >> item2)
	{
	  // don't worry, Sales_item item is initialized when created
	  if(item1.isbn() == item2.isbn())
	    cnt += 1;
	  else
	    {
	      std::cout << item1.isbn() << " recorded " << cnt << std::endl;
	      item1 = item2;
	      cnt = 1;
	    }
	}
      // the last one
      std::cout << item1.isbn() << " recorded " << cnt << std::endl;
    }
  else
    {
      std::cerr << "No data?" << std::endl;
      return -1;
    }
  return 0;
}
