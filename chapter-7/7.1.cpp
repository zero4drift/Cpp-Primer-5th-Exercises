#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

struct Sales_data
{
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main()
{
  Sales_data item1, item2;
  if(cin >> item1.bookNo >> item1.units_sold >> item1.revenue)
    {
      while(cin >> item2.bookNo >> item2.units_sold >> item2.revenue)
	{
	  // don't worry, Sales_item item is initialized when created
	  if(item1.bookNo == item2.bookNo)
	    {
	      item1.units_sold += item2.units_sold;
	      item1.revenue += item2.revenue; 
	    }
	  else
	    {
	      cout << item1.bookNo << " " << item1.units_sold << " "
		   << item1.revenue << endl;
	      item1 = item2;
	    }
	}
      // the last one
      cout << item1.bookNo << " " << item1.units_sold << " "
	   << item1.revenue << endl;
    }
  else
    {
      cerr << "No data?" << endl;
      return -1;
    }
  return 0;
}
