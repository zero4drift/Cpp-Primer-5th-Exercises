#include <cstring>
#include <iostream>
#include <string>

using std::strcmp;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string sa = "time flys";
  string sb = "time flys my friend";
  if(sa != sb) cout << "string sa not equals to sb" << endl;
  char ca1[] = "time flys";
  char ca2[] = "time flys my friend";
  if(strcmp(ca1, ca2)) cout << "C-style character string ca1 not equals to ca2" << endl;
}
