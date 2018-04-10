#include <iostream>

int main()
{
  int i = 0, &r = i;
  auto a = r;
  const int ci = i, &cr = ci;
  auto b = ci;
  auto c = cr;
  auto d = &i;
  auto e = &ci;
  const auto f = ci;
  auto &g = ci;
  std::cout << "a " << a;
  a = 42;			// a = 42
  std::cout << " " << a << std::endl;
  std::cout << "b " << b;
  b = 42;			// b = 42
  std::cout << " " << b << std::endl;
  std::cout << "c " << c;
  c = 42;			// c = 42
  std::cout << " " << c << std::endl;
  d = 42;			// false, types not match;
  e = 42;			// false, types not match;
  g = 42;			// g is a reference to const int
}
  
