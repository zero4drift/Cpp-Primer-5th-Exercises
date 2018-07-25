#include <iostream>
#include <string>
#include <bitset>

using std::bitset;

void to_fibo_7(bitset<35> &b)
{
  b.reset();
  b.set(0);
  b.set(6);
  b.set(10);
  b.set(11);
  b.set(15);
  b.set(17);
  b.set(23);
  b.set(25);
  b.set(27);
  b.set(28);
  b.set(30);
  b.set(32);
  b.set(34);
}

int main()
{
  std::string fibo = "10101011010100000101000110001000001";
  bitset<35> fibonacci(fibo);
  std::cout << fibonacci << std::endl;
  bitset<35> test;
  to_fibo_7(test);
  std::cout << test << std::endl;
}
