#include <random>
#include <iostream>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::endl;

unsigned random_unsigned()
{
  static default_random_engine e;
  static uniform_int_distribution<unsigned> u;
  return u(e);
}

int main()
{
  for(int i = 10; i != 0; --i)
    cout << random_unsigned() << endl;
}
