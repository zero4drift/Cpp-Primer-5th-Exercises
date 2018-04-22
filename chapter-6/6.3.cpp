#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned fract(unsigned x)
{
  unsigned rel = 1;
  while(x > 0)
    rel *= x--;
  return rel;
}

int main()
{
  cout << "Enter a integer above 0 to competer its fraction: ";
  unsigned i;
  cin >> i;
  unsigned result = fract(i);
  cout << "The fraction of " << i << " is " << result << endl;
}
