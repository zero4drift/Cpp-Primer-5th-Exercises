#include <iostream>
#include <string>

int main()
{
  const std::string s = "keep out!";
  for(auto &c : s)		// legal if c would not be modified
    std::cout << c << std::endl;
}
