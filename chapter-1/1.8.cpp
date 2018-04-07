#include <iostream>

int main()
{
  std::cout << "/*";
  std::cout << "*/";
  // std::cout << /* "*/" */; missing terminating "
  std::cout << /* "*/" */";
  std::cout << /* "*/" /* "/*" */;
  return 0;
}
