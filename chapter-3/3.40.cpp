#include <cstring>
#include <iostream>

using std::strcpy;
using std::strcat;
using std::cout;
using std::endl;

int main()
{
  const char ca1[] = "time flys";
  const char ca2[] = " my friend";
  const size_t new_size = strlen(ca1) + strlen(ca2) + 1;
  char ca3[new_size];
  strcpy(ca3, ca1);
  strcat(ca3, ca2);
  cout << ca3 << endl;
}
