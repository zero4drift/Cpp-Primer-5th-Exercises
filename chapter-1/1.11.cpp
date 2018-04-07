#include <iostream>

int main()
{
  int v1, v2;
  std::cout << "Please enter two integers in ascending order:" << std::endl;
  std::cin >> v1 >> v2;
  while(v1 <= v2)
    {
      std::cout << v1 << std::endl;
      ++v1;
    }
  return 0;
}
