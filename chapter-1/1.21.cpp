#include <iostream>
#include "Sales_item.h"

int main()
{
  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  // member function has not been introduced until 1.5.2
  std::cout << item1 + item2 << std::endl;
  return 0;
}
