#include <iostream>
#include "Sales_data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
  Sales_data total(cin);
  if(cin)
    {
      Sales_data trans;
      while(read(cin, trans))	// statement like this is more suitable 
	{
	  if(total.isbn() == trans.isbn())
	    total.combine(trans);
	  else
	    {
	      print(cout, total) << endl;
	      total = trans;
	    }
	}
      print(cout, total) << endl;
    }
  else
    {
      cerr << "No data?!" << endl;
    }
}
