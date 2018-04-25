#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::endl;

int main()
{
  Sales_data item1, item2;
  if(read(cin, item1))
    {
      while(read(cin, item2))
	{
	  // don't worry, Sales_item item is initialized when created
	  if(item1.isbn() == item2.isbn())
	    item1.combine(item2);
	  else
	    {
	      print(cout, item1) << endl;
	      item1 = item2;
	    }
	}
      // the last one
      print(cout, item1) << endl;
    }
  else
    {
      std::cerr << "No data?" << std::endl;
      return -1;
    }
  return 0;
}
