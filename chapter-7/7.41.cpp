#include <iostream>
#include "Sales_data.hpp"

using std::cin;
using std::cout;

int main()
{
  Sales_data item1;
  cout << "\n\n";
  Sales_data item2("12345");
  cout << "\n\n";
  Sales_data item3("54321", 12, 23.00);
  cout << "\n\n";
  Sales_data item4(cin);
};
