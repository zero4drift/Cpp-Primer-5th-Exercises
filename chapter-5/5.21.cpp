#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  bool repeated = false;
  string s1, s2;
  while(cin >> s1)
    {
      if(islower(s1[0]))
	 continue;
      if(s2 == s1)
	{
	  repeated = true;
	  break;
	}
      else
	s2 = s1;
    }
  if(!repeated)
    cout << "No repeat detected." << endl;
  else
    cout << s1 << " repeats 2 times." << endl;
}
