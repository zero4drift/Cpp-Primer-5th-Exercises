#include <iostream>
#include "Sales_data.hpp"
#include "Sales_data_exception.hpp"

using std::cerr;
using std::endl;
using std::cin;

int main()
{
  Sales_data item1, item2, sum;
  while(cin >> item1 >> item2)
    sum = item1 + item2;
  // just like said in section 18.1.1 
  // for on throwed exception, if there is no matched catch expression
  // program calls std library function terminate to terminate program processing
}


// int main()
// {
//   Sales_data item1, item2, sum;
//   while(cin >> item1 >> item2)
//     {
//       try
// 	{
// 	  sum = item1 + item2;
// 	}
//       catch(const isbn_mismatch &e)
// 	{
// 	  cerr << e.what() << ": left isbn(" << e.left
// 	       << ") right isbn(" << e.right << ")" << endl;
// 	}
//     }
// }
