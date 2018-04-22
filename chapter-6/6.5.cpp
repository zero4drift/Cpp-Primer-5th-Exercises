#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned abs_value(int i)
{
  return i >=0 ? i : -i;
}

int main()
{
  cout << "Please a integer to compute its abs value: ";
  int ival;
  cin >> ival;
  unsigned result = abs_value(ival);
  cout << "The abs value of " << ival << " is " << result << endl;
}
