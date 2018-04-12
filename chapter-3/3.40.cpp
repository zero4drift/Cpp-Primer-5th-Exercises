#include <cstring>
#include <iostream>

using std::strcpy;
using std::strcat;
using std::cout;
using std::endl;

int main()
{
  char ca1[] = "time flys";
  char ca2[] = " my friend";
  char ca3[20];
  strcpy(ca3, ca1);
  strcat(ca3, ca2);
  cout << ca3 << endl;
}
