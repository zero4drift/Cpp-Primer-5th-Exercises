#include <iostream>

int main()
{
  // 1.9
  int sum = 0;
  for(int val = 50; val <= 100; ++val)
    {
      sum += val;
    }
  std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;
  // 1.10
  for(int val = 10; val >= 0; --val)
    {
      std::cout << val << std::endl;
    }
  // 1.11
  int v1, v2;
  std::cout << "Please enter two integers in ascending order:" << std::endl;
  std::cin >> v1 >> v2;
  for(int val = v1; val <= v2; ++val)
    {
      std::cout << val << std::endl;
    }
  return 0;
}
