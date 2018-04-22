#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void reset(int &r)
{
  r = 0;
}

int main()
{
  cout << "Enter a int num: ";
  int i;
  cin >> i;
  cout << "Before reset the value is: " << i << endl;
  reset(i);
  cout << "After reset the value is: " << i << endl;
}
