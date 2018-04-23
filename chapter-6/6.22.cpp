#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void exchange(int *p1, int *p2)
{
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int main()
{
  cout << "Please enter two integers: ";
  int i1, i2;
  cin >> i1 >> i2;
  exchange(&i1, &i2);
  cout << "After exchange the first is " << i1 << " the second is " << i2 << endl;
}
