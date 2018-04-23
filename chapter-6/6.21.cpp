#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int compare(int i, int *p)
{
  return i >= *p ? i : *p;
}

int main()
{
  cout << "Please enter two integers: ";
  int i1, i2;
  cin >> i1 >> i2;
  int bigger_one = compare(i1, &i2); // the second parameter should be int* type
  cout << "The bigger one is " << bigger_one << endl;
}
