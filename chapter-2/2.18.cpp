#include <iostream>

int main()
{
  int i = 3, *p = &i;
  *p = 4;
  std::cout << *p << " " << i << std::endl;
  p = nullptr;
}
