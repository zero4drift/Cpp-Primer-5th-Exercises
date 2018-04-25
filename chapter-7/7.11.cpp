#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin;
using std::string;

int main()
{
  Sales_data item1;		// using default constrcutor
  string number = "1234567";
  Sales_data item2(number);
  unsigned u = 6;
  double p = 5.6;
  Sales_data item3(number, u, p);
  Sales_data item4(cin);
}
