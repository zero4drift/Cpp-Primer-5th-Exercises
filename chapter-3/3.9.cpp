#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cout << s[0] << std::endl;		// illegal, s is an empty string, s[0] is undefined
}
