#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  unsigned cnt = 0;
  string line;
  while(getline(cin, line))
    {
      ++cnt;			// getline reads from cin and stores it in a string object excpets for the tail '\n'
      for(auto &ch : line)
	{
	  switch(ch)
	    {
	    case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': case 'E': case 'I': case 'O': case 'U': case ' ': case '\t':
	      ++cnt;
	      break;
	    }
	}
    }
  cout << cnt << endl;
}
