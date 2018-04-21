#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  unsigned cnt = 0;
  char ch;
  bool isf;
  while(cin >> ch)
    {
      switch(ch)
	{
	case 'f':
	  {
	    if(!isf) isf = true;
	    else
	      {
		++cnt;
		isf = false;
	      }
	  }
	  break;
	case 'l':
	  if(isf)
	    {
	      ++cnt;
	      isf = false;
	    }
	  break;
	case 'i':
	  if(isf)
	    {
	      ++cnt;
	      isf = false;
	    }
	  break;
	default:
	  isf = false;
	  break;
	}
    }
  cout << cnt<< endl;
}
