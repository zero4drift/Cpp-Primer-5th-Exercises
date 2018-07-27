#include <ctime>
#include <random>
#include <iostream>

using std::time;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::cin;
using std::endl;

unsigned random_unsigned(unsigned s = time(0))
{
  static default_random_engine e(s);
  static uniform_int_distribution<unsigned> u;
  return u(e);
}

int main()
{
  cout << "Please input a seed of unsigned int type: " << endl;
  unsigned s;
  cin >> s;
  for(int i = 10; i != 0; --i)
    cout << random_unsigned(s) << endl;
}
