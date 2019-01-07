// See a friend class BookNoPtr of class Sales_data in Sales_data.h.

#include <iostream>
#include "Sales_data.hpp"

using std::cout;
using std::endl;

int main()
{
  Sales_data s("hello");
  BookNoPtr p;
  cout << s.*(p.data()) << endl;;
}
