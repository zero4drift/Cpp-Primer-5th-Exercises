// a, 0-201-99999-9 10 24.95 generates a valid Sales_data object with right data members.
// illegal input, the interger part of 24.95 would be stored in data member units_sold, then left part .95 would be treated as third input and converted to a float stored in this object as data member price; finally the data of this object contains is false.

#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
  Sales_data a;
  cin >> a;
  cout << a << endl;
}
