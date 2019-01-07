#include <iostream>
#include "Sales_data.hpp"

using std::cin;
using std::endl;
using std::cerr;

int main()
{
  Sales_data item1, item2;
  if(cin >> item1.bookNo >> item1.units_sold >> item1.revenue)
    {
      while(cin >> item2.bookNo >> item2.units_sold >> item2.revenue)
	{
	  // don't worry, Sales_item item is initialized when created
	  if(item1.isbn() == item2.isbn())
	    item1.combine(item2);
	  else
	    {
	      cout << item1.isbn() << " " << item1.units_sold << " " << item1.revenue << endl;
	      item1 = item2;
	    }
	}
      // the last one
      cout << item1.isbn() << " " << item1.units_sold << " " << item1.revenue << endl;
    }
  else
    {
      cerr << "No data?" << std::endl;
      return -1;
    }
  return 0;
}
