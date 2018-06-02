#include <iostream>
#include <forward_list>
#include <string>

using std::cout;
using std::endl;
using std::forward_list;
using std::string;

void insert_ss(forward_list<string> &flst, string s1, string s2)
{
  auto curr = flst.begin();
  decltype(curr) temp;
  while(curr != flst.end())
    {
      if(*curr == s1)
	{
	  flst.insert_after(curr, s2);
	  return;
	}
      else
	{
	  temp = curr;
	  ++curr;
	}
    }
  flst.insert_after(temp, s2);
}

int main()
{
  forward_list<string> sample = {"hello", "amigo", "aloha", "nihao"};
  insert_ss(sample, "amigo", "test");
  insert_ss(sample, "surprise", "ok");
  for(const auto &s : sample)
    cout << s << endl;
}
