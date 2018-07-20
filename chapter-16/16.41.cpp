#include <iostream>

template <typename T>
auto sum(T a, T b) -> decltype(a + b)
{
  return a + b;
}

int main()

{

  auto s = sum(123456789123456789123456789123456789123456789, 123456789123456789123456789123456789123456789);
  std::cout << s << std::endl;
}
