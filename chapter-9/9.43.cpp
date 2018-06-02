#include <string>
#include <iostream>

using std::string;
using std::cerr;
using std::cout;
using std::endl;

string &my_replace(string &s, string oldVal, string newVal)
{
  string::difference_type len = oldVal.size();
  string::iterator iter1 = s.begin(), iter2;
  while(s.end() - iter1 >= len)
    {
      iter2 = iter1 + len;
      string temp(iter1, iter2);
      if(temp == oldVal)
	{
	  iter1 = s.erase(iter1, iter2);
	  iter1 = s.insert(iter1, newVal.begin(), newVal.end());
	  iter1 += newVal.size();
	}
      else
	++iter1;
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
