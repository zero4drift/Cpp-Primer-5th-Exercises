#include <iostream>

int main()
{
  int v1, v2;
  std::cout << "Please enter two integers:" << std::endl;
  std::cin >> v1 >> v2;
  if(v1 <= v2)
    {
      while(v1 <= v2)
	{
	  std::cout << v1 << std::endl;
	  ++v1;
	}
    }
  else
    {
      while(v2 <= v1)
	{
	  std::cout << v2 << std::endl;
	  ++v2;
	}
    }
  return 0;
}
