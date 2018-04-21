#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string s, repeat, maxrepeat;
  unsigned cnt = 1, maxcnt = 1;
  while(cin >> s)
    {
      if(repeat == s) ++cnt;
      else
	{
	  if(cnt >= 2 && cnt >= maxcnt)
	    {
	      maxrepeat = repeat;
	      maxcnt = cnt;
	    }
	  cnt = 1;
	  repeat = s;
	}
    }
  if(cnt >= 2 && cnt >= maxcnt)
    {
      maxrepeat = repeat;
      maxcnt = cnt;
    }
  if(maxcnt != 1)
    cout << maxrepeat << " repeated " << maxcnt << " times." << endl;
  else
    cout << "No word has repeated." << endl;
}
