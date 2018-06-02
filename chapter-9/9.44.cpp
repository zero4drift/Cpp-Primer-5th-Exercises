#include <string>
#include <iostream>

using std::string;
using std::cerr;
using std::cout;
using std::endl;

string &my_replace(string &s, string oldVal, string newVal)
{
  decltype(s.size()) index = 0, len = oldVal.size();
  while(s.size() - index >= len)
    {
      string temp = s.substr(index, len);
      if(temp == oldVal)
	{
	  s.replace(index, len, newVal);
	  index += newVal.size();
	}
      else
	++index;
    }
  return s;
}

int main()
{
  string s1 = "test test test test test skip test skiptesttest";
  my_replace(s1, "test", "yes");
  cout << s1 << endl;
  string s2 = "short";
  my_replace(s2, "testtest", "no");
  cout << s2 << endl;
  string s3 = "test test test skipendhere";
  my_replace(s3, "test", "yes");
  cout << s3 << endl;
}
