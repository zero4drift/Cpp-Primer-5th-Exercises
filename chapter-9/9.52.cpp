// As much I can do here, if given some functions on transforming char to int and the reverse transform, it would exactly meet the requirement

#include <stack>
#include <string>
#include <iostream>

using std::stack;
using std::string;
using std::cout;
using std::endl;

int main()
{
  string s = "(((1+2)+3)+4)";
  stack<char> sc;
  int temp = 0;
  for(const auto &c : s)
    {
      if(c != ')')
	{
	  sc.push(c);
	}
      else
	{
	  while(sc.top() != '(')
	    {
	      if(isdigit(sc.top())) temp += (sc.top() - 48);
	      sc.pop();
	    }
	  sc.pop();
	}
    }
  cout << temp << endl;
}
