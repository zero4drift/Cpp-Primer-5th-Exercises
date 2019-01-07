#include <iostream>
#include "Chapter6.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Enter a integer above 0 to competer its fraction: ";
  unsigned i;
  cin >> i;
  unsigned result = fract(i);
  cout << "The fraction of " << i << " is " << result << endl;
}
