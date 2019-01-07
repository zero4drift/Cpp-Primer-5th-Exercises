#include <iostream>
#include <vector>
#include "String.hpp"

int main()
{
  std::vector<String> vs;
  std::cout << "Initialize vector<String> object" << std::endl;
  String s("hello");
  std::cout << "Initialize String object" << std::endl;
  std::cout << "Push first" << std::endl;
  vs.push_back(s);
  std::cout << "Push second" << std::endl;
  vs.push_back(s);
  std::cout << "Push third" << std::endl;
  // vs.push_back(String("word"));
  vs.push_back(s);
}
// echo "String::String(const String &s) six times
// for there is a memory reallocation processing during push_back.
