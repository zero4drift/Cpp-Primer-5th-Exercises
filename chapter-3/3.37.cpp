#include <iostream>

using std::cout;
using std::endl;

int main()
{
  const char ca[] = {'h', 'e', 'l', 'l', 'o'};
  const char *cp = ca;		// that can do, types match
  while(*cp)			// since there is no '\0' in array ca, this while loop would repeat until '\0' encountered in ram.
    {
      cout << *cp << endl;
      ++cp;
    }
  
}
