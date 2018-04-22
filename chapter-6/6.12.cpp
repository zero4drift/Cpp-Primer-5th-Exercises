#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void exchange(int &p1, int &p2)	// of course called by reference is better
{
  int temp;
  temp = p1;
  p1 = p2;
  p2 = temp;
}

int main()
{
  cout << "Please enter integer numbers: ";
  int i1, i2;
  cin >> i1 >> i2;
  cout << "first int num: " << i1
       << " second int num: " << i2 << endl;
  exchange(i1, i2);		// just pass the variable, not a &i1...
  cout << "after exchanging first int num: " << i1
       << " second int num: " << i2 << endl;
}

