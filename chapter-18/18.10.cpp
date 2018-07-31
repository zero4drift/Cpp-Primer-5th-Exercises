#include <iostream>
#include "Sales_data.h"
#include "Sales_data_exception.h"

using std::cerr;
using std::endl;
using std::cin;

// int main()
// {
//   Sales_data item1, item2, sum;
//   while(cin >> item1 >> item2);
//   sum = item1 + item2;
// }


int main()
{
  Sales_data item1, item2, sum;
  while(cin >> item1 >> item2)
    {
      try
	{
	  sum = item1 + item2;
	}
      catch(const isbn_mismatch &e)
	{
	  cerr << e.what() << ": left isbn(" << e.left
	       << ") right isbn(" << e.right << ")" << endl;
	}
    }
}
