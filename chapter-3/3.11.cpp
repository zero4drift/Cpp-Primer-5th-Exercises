#include <iostream>
#include <string>

int main()
{
  const std::string s = "keep out!";
  for(auto &c : s)		// legal, a reference to constant char object
    std::cout << c << std::endl;
}
